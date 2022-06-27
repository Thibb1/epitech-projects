/*
** EPITECH PROJECT, 2021
** minishell.c
** File description:
** calls shell functions
*/

#include "my_shell.h"

str_list *env;

int minishell(char **env_arr)
{
    env = init_env(env_arr);
    cmd = NULL;
    return (shell(isatty(STDIN_FILENO)));
}

void signal_ctrl_c(int sig)
{
    (void) sig;
    my_printf("\n");
    my_prompt();
}

void signal_ctrl_z(int sig)
{
    (void) sig;
}