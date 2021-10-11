/*
** EPITECH PROJECT, 2020
** info_file.c
** File description:
** get info from file
*/

#include "../include/my.h"
#include "../include/ls.h"

char file_type(int m)
{
    if (S_ISREG(m))
        return ('-');
    if (S_ISDIR(m))
        return ('d');
    if (S_ISCHR(m))
        return ('c');
    if (S_ISBLK(m))
        return ('b');
    if (S_ISLNK(m))
        return ('l');
    if (S_ISFIFO(m))
        return ('p');
    if (S_ISSOCK(m))
        return ('s');
    return ('?');
}

void ift_right(st st, char *mode)
{
    mode[0] = 0;
    my_strcat(mode, st.st_mode & S_IRUSR ? "r" : "-");
    my_strcat(mode, st.st_mode & S_IWUSR ? "w" : "-");
    my_strcat(mode, st.st_mode & S_IXUSR ? "x" : "-");
    my_strcat(mode, st.st_mode & S_IRGRP ? "r" : "-");
    my_strcat(mode, st.st_mode & S_IWGRP ? "w" : "-");
    my_strcat(mode, st.st_mode & S_IXGRP ? "x" : "-");
    my_strcat(mode, st.st_mode & S_IROTH ? "r" : "-");
    my_strcat(mode, st.st_mode & S_IWOTH ? "w" : "-");
    my_strcat(mode, st.st_mode & S_IXOTH ? "x" : "-");
}

void init_info(st st, ift *ift)
{
    ift->type = file_type(st.st_mode);
    ift_right(st, ift->mode);
    ift->inode = st.st_ino;
    ift->nlink = st.st_nlink;
    ift->size = st.st_size;
    ift->blocks = st.st_blocks ? (st.st_blocks * 512) : 0;
    ift->minor = my_grep("cb", ift->type) ? (int)minor(st.st_rdev) : -1;
    ift->major = st.st_dev;
    ift->uid = st.st_uid;
    ift->gid = st.st_gid;
}
