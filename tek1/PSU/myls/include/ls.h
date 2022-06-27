/*
** EPITECH PROJECT, 2020
** ls.h
** File description:
** ls utils
*/

#ifndef _LS
#define _LS

#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <dirent.h>

typedef struct ls_s {
    int aflag;
    int lflag;
    int recflag;
    int dflag;
    int tflag;
    int revflag;
    int path;
    char **pathname;
} ls_s;

typedef struct ift_s {
    char type;
    char mode[10];
    int inode;
    int nlink;
    int size;
    int blocks;
    int minor;
    int major;
    int uid;
    int gid;
} ift;

typedef struct stat st;

ls_s get_flag(int ac, char *av[]);
void process_path(ls_s d);

void file_info(char *path, char *d_name, ls_s d);
void file_name(char *path, ls_s d);
void init_st(st *st, const char *path);
void init_info(st st, ift *ift);
#endif
