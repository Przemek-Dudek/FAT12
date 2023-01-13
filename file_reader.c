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

    struct disk_t *disc = calloc(1, sizeof(struct disk_t));
    if(disc == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    disc->f = f;

    return disc;
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

    if(pdisk->opened) {
        free(pdisk->opened);
    }

    free(pdisk);

    return 0;
}

//##############################################################################################

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

    volume->disk = pdisk;
    pdisk->opened = volume;

    if(disk_read(pdisk, first_sector, NULL, 1) == -1) {
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

struct file_t* file_open(struct volume_t* pvolume, const char* file_name)
{
    if(pvolume == NULL || file_name == NULL) {
        return NULL;
    }

    return NULL;
}


int file_close(struct file_t* stream)
{
    if(stream == NULL) {
        return -1;
    }

    return 0;
}


size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream)
{
    if(ptr == NULL || size == 0 || nmemb == 0 || stream == NULL) {
        return -1;
    }

    return 1;
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

