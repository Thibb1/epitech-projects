/*
** EPITECH PROJECT, 2020
** builtin.c
** File description:
** sh funct
*/

#include "my_sh.h"

int check_builtin(char *str) {
    if (!my_strcmp(str, "cd"))
        return (1);
    if (!my_strcmp(str, "setenv"))
        return (2);
    if (!my_strcmp(str, "unsetenv"))
        return (3);
    if (!my_strcmp(str, "env"))
        return (4);
    if (!my_strcmp(str, "exit"))
        return (5);
    return (0);
}

void run_builtin(char **cmd, char **env)
{
    if (!my_strcmp(cmd[0], "cd"))
        builtin_cd(cmd, env);
    if (!my_strcmp(cmd[0], "setenv"))
        builtin_setenv(cmd, env);
    if (!my_strcmp(cmd[0], "unsetenv"))
        builtin_unsetenv(cmd, env);
    if (!my_strcmp(cmd[0], "env")) {
        print_arr(env);
    }
    if (!my_strcmp(cmd[0], "exit")) {
        free_arr(cmd);
        free_arr(env);
        exit(SUCCESS);
    }
}