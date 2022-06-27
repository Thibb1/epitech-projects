/*
** EPITECH PROJECT, 2020
** myls.c
** File description:
** short file description
*/

#include "../include/my.h"
#include "../include/ls.h"

int check_dir(char **path, const int foldernb)
{
    DIR *dir;
    int i = 0;

    for (; i < foldernb; i++) {
        dir = opendir(path[i]);
        if (dir == NULL)
            my_printf("my_ls: cannot access '%s': No such file or directory\n",
                path[i]);
        closedir(dir);
    }
    return (i);
}

void folder_size(char *path, ls_s d)
{
    DIR *dir = opendir(path);
    struct dirent *dirent;
    st stat;
    int folder_size = 0;
    char *str;

    if (!d.lflag)
        return;
    str = malloc(sizeof(char) * 200);
    for (int i = 0; (dirent = readdir(dir)) != 0; i++) {
        if (dirent->d_name[0] == '.' && !d.aflag)
            continue;
        my_strcat(my_strcat(my_strcat(str, path), "/"), dirent->d_name);
        init_st(&stat, str);
        folder_size += stat.st_blocks;
        str[0] = 0;
    }
    my_printf("total %d\n", folder_size / 2);
    free(str);
    closedir(dir);
}

void read_dir(char *path, ls_s d)
{
    static int a = 0;
    DIR *dir;
    dir = opendir(path);
    if (dir == 0)
        return;
    if (d.path > 1)
        my_printf("%s:\n", path);
    closedir(dir);
    folder_size(path, d);
    file_name(path, d);
    my_printf(++a == d.path || d.path < 2 ? "": "\n");
}

void process_path(ls_s d)
{
    if (d.path) {
        d.path = check_dir(d.pathname, d.path);
        for (int i = d.path - 1; i >= 0; i--)
            read_dir(d.pathname[i], d);
    } else
        read_dir("./", d);
}

ls_s get_flag(int ac, char *av[])
{
    ls_s data = {0, 0, 0, 0, 0, 0, 0, NULL};

    m_check(data.pathname = malloc(sizeof(char *) * ac));
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-')
            for (int b = 1; av[i][b]; b++) {
                data.aflag += my_grep("a", av[i][b]);
                data.lflag += my_grep("l", av[i][b]);
                data.recflag += my_grep("R", av[i][b]);
                data.dflag += my_grep("d", av[i][b]);
                data.tflag += my_grep("t", av[i][b]);
                data.revflag += my_grep("r", av[i][b]);
            }
        else {
            m_check(data.pathname[data.path] =
                malloc(sizeof(char) * my_strlen(av[i])));
            my_strcpy(data.pathname[data.path++], av[i]);
        }
    }
    return (data);
}
