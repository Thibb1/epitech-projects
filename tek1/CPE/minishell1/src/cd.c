/*
** EPITECH PROJECT, 2020
** cd.c
** File description:
** sh funct
*/

#include <limits.h>
#include "my_sh.h"

void builtin_cd(char **cmd, char **env)
{
    int len = arr_len(cmd);

    if (len == 1) {
        if (get_env_str("HOME", env) != NULL)
            my_cd(get_env_str("HOME", env), env);
    } else if (len == 2) {
        my_cd(get_cd_path(cmd[1], env), env);
    } else
        my_ferror("cd: Too many arguments.");
}

void my_cd(char *path, char **env)
{
    char buf[PATH_MAX];

    if (path == NULL)
        return;
    chdir(path);
    my_unsetenv("OLDPWD", env);
    my_setenv("OLDPWD", get_env_str("PWD", env), env);
    my_unsetenv("PWD", env);
    if (getcwd(buf, sizeof(buf)) != NULL)
        my_setenv("PWD", buf, env);
    else
        my_setenv("PWD", path, env);
}

char *get_cd_path(char *cmd, char **env)
{
    struct stat st;
    char *path;

    if (!my_strcmp(cmd, "-"))
        return (get_env_str("OLDPWD", env));
    if (!my_strcmp(cmd, "~"))
        return (get_env_str("HOME", env));
    if (lstat(cmd, &st) != -1)
        return (cmd);
    path = malloc(sizeof(char) * (my_strlen(cmd) + my_strlen(get_env_str("PWD",
        env)) + 2));
    my_strcat(path, get_env_str("PWD", env));
    my_strcat(path, "/");
    my_strcat(path, cmd);
    if (lstat(path, &st) != -1) {
        return (path);
    }
    free (path);
    return (NULL);
}