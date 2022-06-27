/*
** EPITECH PROJECT, 2021
** cd.c
** File description:
** cd builtin
*/

#include "my_shell.h"

int file_exist(char *str)
{
    struct stat st;

    if (lstat(str, &st) == -1)
        return (0);
    return (1);
}

int builtin_cd(char **cmd)
{
    int len = arr_len(cmd);

    if (len == 1) {
        return (my_cd("~"));
    } else if (len == 2) {
        return (my_cd(cmd[1]));
    } else {
        my_ferror("cd: Too many arguments.");
        return (1);
    }
    return (0);
}

int my_cd(char *cmd)
{
    char *path = get_cd_path(cmd);
    size_t len = 4096;
    char *pwd = NULL;
    struct stat st;

    pwd = getcwd(pwd, len);
    my_setenv("OLDPWD", pwd);
    free(pwd);
    if (lstat(path, &st) == -1 || chdir(path) == -1) {
        print_cd_error(cmd, path, st);
        free(path);
        return (1);
    }
    pwd = NULL;
    pwd = getcwd(pwd, len);
    my_setenv("PWD", pwd);
    free(pwd);
    free(path);
    return (0);
}

char *get_cd_path(char *cmd)
{
    char *path = NULL;
    int len = my_strlen(cmd);
    str_list *old_pwd = env;
    str_list *home = env;

    GET_STR_LIST(old_pwd, "OLDPWD=", 7);
    GET_STR_LIST(home, "HOME=", 5);
    if (!my_strcmp(cmd, "-"))
        return (my_strdup(old_pwd ? my_grep_str('=', old_pwd->str) : ""));
    if (!my_strcmp(cmd, "~"))
        return (my_strdup(home ? my_grep_str('=', home->str) : ""));
    if (!my_strncmp(cmd, "~/", 2) && home) {
        len += my_strlen(my_grep_str('=', home->str));
        if (m_check(path = malloc(sizeof(char) * len)))
            return (NULL);
        path[0] = 0;
        return (my_strcat(my_strcat(path, my_grep_str('=', home->str)),
            &cmd[1]));
    }
    return (my_strdup(cmd));
}