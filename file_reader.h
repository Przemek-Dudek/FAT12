#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

struct disk_t {
    FILE *f;
    struct volume_t *opened;
};

struct volume_t {
    struct disk_t* disk;
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

struct file_description_t {
    char nazwa[8];
    char rozszerzenie[3];
    enum atribute_t atribute;   //uint8
    uint8_t isReserved;
    uint8_t createTime;
    struct time_godziny_t godzina;
    struct time_dzien_t dzien;
    uint16_t lastTime;
    uint16_t first_cluster_older;
    struct time_godziny_t lastModeHour;
    struct time_dzien_t lastModeDate;
    uint16_t first_cluster_younger;
    uint32_t size;
};

struct file_t{
    struct volume_t* vol;
    struct cluster_t* clus;
    struct file_description_t description;
    uint16_t cluster_number;
    uint16_t file_position;
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