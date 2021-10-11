/*
** EPITECH PROJECT, 2020
** lsutils.c
** File description:
** utils func for ls
*/

#include "../include/my.h"
#include "../include/ls.h"

void init_st(st *st, const char *path)
{
    if (stat(path, st)) {
        my_printf("can't read stats of : %s\n", path);
        exit (84);
    }
}

void file_info(char *path, char *d_name, ls_s d)
{
    st stat;
    ift ift;
    struct group *g;
    struct passwd *u;
    char *str;
    if (!d.lflag)
        return;
    str = malloc(sizeof(char) * (my_strlen(path) + my_strlen(d_name) + 2));
    if (d_name[0] != '.' || d.aflag) {
        str[0] = 0;
        my_strcat(my_strcat(my_strcat(str, path), "/"), d_name);
        init_st(&stat, str);
        init_info(stat, &ift);
        u = getpwuid(ift.uid);
        g = getgrgid(ift.gid);
        my_printf("%c%s %d %s ", ift.type, ift.mode, ift.nlink, u->pw_name);
        my_printf("%s %d ", g->gr_name, ift.size);
        my_printf("%.12s ", (ctime(&stat.st_mtime) + 4));
    }
    free(str);
}

void file_name(char *path, ls_s d)
{
    DIR *dir = opendir(path);
    struct dirent *dirent;

    for (int i = 0; (dirent = readdir(dir)) != 0; i++) {
        file_info(path, dirent->d_name, d);
        if (dirent->d_name[0] != '.' || d.aflag)
            my_printf("%s\n", dirent->d_name);
    }
}
