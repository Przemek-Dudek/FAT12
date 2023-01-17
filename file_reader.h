#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>

struct disk_t {
    FILE *f;
};

struct volume_t {
    struct fat_super_t *SuperSector;
    struct disk_t *disk;

    int FAT1_Pos;
    int FAT2_Pos;
    int FAT_sectors;

    int ROOT_Dir_Pos;
    int ROOT_Sectors;

    int volume_size;
    int user_size;
    int number_of_cluster_per_volume;

    int cluster2_position;

    int DATA_Pos;
};

struct time_godziny_t{
    uint16_t sekundy:5;
    uint16_t minuty:6;
    uint16_t godziny:5;
};

struct time_dzien_t{
    uint16_t dzien:5;
    uint16_t miesiac:4;
    uint16_t rok:7;
};

enum atribute_t{
    read_only = 0x01,
    hidden_file = 0x02,
    system_file = 0x04,
    volume_label = 0x08,
    directory = 0x10,
    archived = 0x20,
    lfn = 0x0F
};

struct fat_entry_t {
    char name[8];
    char extenstion[3];
    uint8_t attributes;

    uint8_t __some_data[6];
    uint16_t __some_data2;

    uint16_t high_cluster_index;
    uint16_t __some_data3[2];
    uint16_t low_cluster_index;
    uint32_t file_size;

} __attribute__(( packed ));


struct file_t{
    struct volume_t* vol;
    struct cluster_t* clus;
    struct fat_entry_t *entry;

    int file_pos;

    char *buff;
};

struct dir_t {
    struct volume_t* vol_hand;
    uint16_t dir_position;
};

struct cluster_t {
    uint16_t* handle;
    size_t size;
};

struct dir_entry_t {
    char *name;
    int size;
    int is_archived;
    int is_readonly;
    int is_system;
    int is_hidden;
    int is_directory;
};

struct fat_super_t {
    uint8_t __jump_code[3];
    char oem_name[8];

    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t fat_count;
    uint16_t root_dir_capacity;
    uint16_t logical_sectors16;
    uint8_t __reserved;
    uint16_t sectors_per_fat;

    uint32_t __reserved2;

    uint32_t hidden_sectors;
    uint32_t logical_sectors32;

    uint16_t __reserved3;
    uint8_t __reserved4;

    uint32_t serial_number;

    char label[11];
    char fsid[8];

    uint8_t __boot_code[448];
    uint16_t magic;
} __attribute__(( packed ));

struct disk_t* disk_open_from_file(const char* volume_file_name);
int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read);
int disk_close(struct disk_t* pdisk);

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector);
int fat_close(struct volume_t* pvolume);

struct file_t* file_open(struct volume_t* pvolume, const char* file_name);
int file_close(struct file_t* stream);
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream);
int32_t file_seek(struct file_t* stream, int32_t offset, int whence);

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path);
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry);
int dir_close(struct dir_t* pdir);