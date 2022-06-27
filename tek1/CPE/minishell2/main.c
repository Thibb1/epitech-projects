/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** calls main funct
*/

#include "my_shell.h"

cmd_list *cmd;

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    return (minishell(env));
}