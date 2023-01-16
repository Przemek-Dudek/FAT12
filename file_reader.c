#include "file_reader.h"
#include "tested_declarations.h"
#include "rdebug.h"


struct disk_t* disk_open_from_file(const char* volume_file_name)
{
    if(volume_file_name == NULL) {
        errno = EFAULT;
        return NULL;
    }

    FILE *f = fopen(volume_file_name, "rb");
    if(f == NULL) {
        errno = ENOENT;
        return NULL;
    }

    struct disk_t *disk = calloc(1, sizeof(struct disk_t));
    if(disk == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    disk->f = f;

    return disk;
}


int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read)
{
    if(pdisk == NULL || buffer == NULL) {
        errno = EFAULT;
        return -1;
    }

    if(fseek(pdisk->f, first_sector*512, SEEK_SET) < 0 || (int32_t)fread(buffer, 512, sectors_to_read, pdisk->f) != sectors_to_read) {
        errno = ERANGE;
        return -1;
    }

    return (int)sectors_to_read;
}



int disk_close(struct disk_t* pdisk)
{
    if(pdisk == NULL) {
        errno = EFAULT;
        return -1;
    }

    if(pdisk->f) {
        fclose(pdisk->f);
    }

    free(pdisk);

    return 0;
}

//##############################################################################################

int checkSuperSector(struct fat_super_t *superSector)
{
    if(superSector->bytes_per_sector != 512) {
        return 1;
    }

    if(superSector->fat_count != 2) {
        return 1;
    }

    if(superSector->magic != 0xaa55) {
        return 1;
    }

    return 0;
}

int fat_compare(struct volume_t *volume, struct disk_t* pdisk, uint32_t first_sector)
{
    char buff_FAT1[512], buff_FAT2[512];

    for(int i = 0; i < volume->FAT_sectors; i++) {
        if(disk_read(pdisk, first_sector + volume->FAT1_Pos + i, buff_FAT1, 1) == -1) {
            return 1;
        }

        if(disk_read(pdisk, first_sector + volume->FAT2_Pos + i, buff_FAT2, 1) == -1) {
            return 1;
        }

        for(int j = 0; j < 512; j++) {
            if(buff_FAT1[j] != buff_FAT2[j]) {
                return 1;
            }
        }
    }

    return 0;
}

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector)
{
    if(pdisk == NULL) {
        errno = EFAULT;
        return NULL;
    }

    struct volume_t *volume = calloc(1, sizeof(struct volume_t));
    if(volume == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    char *buffer = malloc(512);
    if(buffer == NULL) {
        errno = ENOMEM;
        free(volume);
        return NULL;
    }

    if(disk_read(pdisk, first_sector, buffer, 1) == -1) {
        errno = EINVAL;
        free(buffer);
        free(volume);
        return NULL;
    }

    struct fat_super_t *superSector = (struct fat_super_t*)buffer;

    if(checkSuperSector(superSector)) {
        free(buffer);
        free(volume);
        errno = EINVAL;
        return NULL;
    }

    volume->disk = pdisk;

    volume->SuperSector = superSector;
    volume->FAT1_Pos = superSector->reserved_sectors;
    volume->FAT2_Pos = superSector->reserved_sectors + superSector->sectors_per_fat;
    volume->FAT_sectors = superSector->sectors_per_fat;

    volume->ROOT_Dir_Pos = superSector->reserved_sectors + superSector->sectors_per_fat*superSector->fat_count;
    volume->ROOT_Sectors = (superSector->root_dir_capacity * sizeof(struct fat_entry_t))/superSector->bytes_per_sector;
    if((superSector->root_dir_capacity * sizeof(struct fat_entry_t)) % superSector->bytes_per_sector) {
        volume->ROOT_Sectors += 1;
    }

    volume->volume_size = superSector->logical_sectors16 == 0 ? superSector->logical_sectors32 : superSector->logical_sectors16;
    volume->user_size = volume->volume_size - (superSector->fat_count * superSector->sectors_per_fat) - superSector->reserved_sectors - volume->ROOT_Sectors;
    volume->number_of_cluster_per_volume = volume->user_size / superSector->sectors_per_cluster;
    if(volume->user_size % superSector->sectors_per_cluster) {
        volume->number_of_cluster_per_volume += 1;
    }

    volume->cluster2_position = volume->ROOT_Dir_Pos + volume->ROOT_Sectors;


    volume->DATA_Pos = volume->ROOT_Dir_Pos + (superSector->root_dir_capacity*32)/512;

    if(fat_compare(volume, pdisk, first_sector)) {
        free(buffer);
        free(volume);
        errno = EINVAL;
        return NULL;
    }

    return volume;
}


int fat_close(struct volume_t* pvolume)
{
    if(pvolume == NULL) {
        errno = EFAULT;
        return -1;
    }

    free(pvolume);

    return 0;
}

//##############################################################################################

int is_valid(char n)
{
    if((n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z')) {
        return 1;
    }

    if((n >= '0' && n <= '9') || n == '_' || n == -27) {
        return 1;
    }

    return 0;
}

struct file_t* file_open(struct volume_t* pvolume, const char* file_name)
{
    if(pvolume == NULL || file_name == NULL) {
        return NULL;
    }

    struct file_t *file = calloc(1, sizeof(struct file_t));
    if(file == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    file->vol = pvolume;

    char *buff = calloc(file->vol->ROOT_Sectors, 512);
    if(buff == NULL) {
        free(file);
        errno = ENOMEM;
        return NULL;
    }

    if(disk_read(file->vol->disk, (uint16_t)(pvolume->FAT2_Pos + pvolume->FAT_sectors), buff, file->vol->ROOT_Sectors) == -1) {
        free(file);
        free(buff);
        errno = ENOMEM;
        return NULL;
    }


    struct fat_entry_t *entry;

    for(int i = 0; i < 24; i++) {
        entry = (struct fat_entry_t*)(buff+i*32);

        char tmp[13];

        for(int j = 0; j < 13; j++) {
            tmp[j] = '\0';
        }

        for(int j = 0; j < (int)strlen(entry->name); j++) {
            if(!is_valid(*(entry->name + j))) {
                break;
            }

            tmp[j] = *(entry->name + j);
        }

        if(is_valid(*(entry->extenstion))) {
            tmp[strlen(tmp)] = '.';
        }

        int name_len = strlen(tmp);

        for(int j = 0; j < (int)strlen(entry->extenstion); j++) {
            if(!is_valid(*(entry->extenstion + j))) {
                break;
            }

            tmp[j+name_len] = *(entry->extenstion + j);
        }

        if(strcmp(tmp, file_name) == 0) {
            break;
        }
    }


    file->entry = entry;

    return file;
}


int file_close(struct file_t* stream)
{
    if(stream == NULL) {
        return -1;
    }

    if(stream->entry != NULL) {
        free(stream->entry);
    }

    free(stream);

    return 0;
}


size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream)
{
    if(ptr == NULL || size == 0 || nmemb == 0 || stream == NULL) {
        return -1;
    }

    uint16_t *buffer = (uint16_t*)malloc((stream->vol->number_of_cluster_per_volume + 2) * sizeof(int));
    if(buffer == NULL) {
        errno = ENOMEM;
        return -1;
    }

    int *fat1_data = calloc(stream->vol->SuperSector->sectors_per_fat*stream->vol->SuperSector->bytes_per_sector, 1);
    if(fat1_data == NULL) {
        free(buffer);
        errno = ENOMEM;
        return -1;
    }

    if(disk_read(stream->vol->disk, stream->vol->FAT1_Pos, fat1_data, stream->vol->SuperSector->sectors_per_fat) == -1) {
        free(buffer);
        free(fat1_data);
        return -1;
    }

    for(int i = 0, j = 0; i < stream->vol->number_of_cluster_per_volume + 2; i += 2, j += 3) {
        uint8_t b1 = fat1_data[j];
        uint8_t b2 = fat1_data[j + 1];
        uint8_t b3 = fat1_data[j + 2];

        int c1 = ((b2 & 0x0F) << 8) | b1;
        int c2 = ((b2 & 0xF0) >> 4) | (b3 << 4);
        buffer[i] = c1;
        buffer[i + 1] = c2;
    }

    uint16_t table[512];

    uint16_t val = stream->entry->low_cluster_index;

    for(int i = 0; val != *buffer; i++) {
        table[i] = val;
        val = buffer[val];

        if(disk_read(stream->vol->disk, (table[i] - 2) * stream->vol->SuperSector->sectors_per_cluster + stream->vol->DATA_Pos, (char*)ptr + i * stream->vol->SuperSector->sectors_per_cluster, stream->vol->SuperSector->sectors_per_cluster) == -1) {
            return -1;
        }
    }





    return nmemb*size;
}


int32_t file_seek(struct file_t* stream, int32_t offset, int whence)
{
    if(stream == NULL || offset == 0 || whence == 0) {
        return -1;
    }

    return 0;
}

//##############################################################################################

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path)
{
    if(pvolume == NULL || dir_path == NULL) {
        return NULL;
    }

    return NULL;
}


int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry)
{
    if(pdir == NULL || pentry == NULL) {
        return -1;
    }

    return 0;
}


int dir_close(struct dir_t* pdir)
{
    if(pdir == NULL) {
        return -1;
    }

    return 0;
}

