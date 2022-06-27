/*
** EPITECH PROJECT, 2020
** prompt.c
** File description:
** sh funct
*/

#include "my_sh.h"

void prompt(int mode, char **env)
{
    char *user = get_env_str("USER", env);
    char *pwd = get_env_str("PWD", env);

    if (mode == STARTUP) {
        my_printf("\e[1;1H\e[2J\033[38;5;27mMinishell v0.1\033[1;0m\n");
    } else if (mode == RUNNING) {
        if (user)
            my_printf("\033[01;32m%s", user);
        if (pwd)
            my_printf("\033[01;32m@%s", pwd);
        my_printf("\033[00m:\033[01;34m\033[00m$ ");
    }
}