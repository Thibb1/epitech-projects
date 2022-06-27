/*
** EPITECH PROJECT, 2020
** simple_input.c
** File description:
** sh funct
*/

#include "my_sh.h"

int one_command_input(char **av, char **env)
{
    exec_tree(av[1], env);
    return (SUCCESS);
}

int tty_one_command(char **env)
{
    int fd;
    char line[LINE_READ + 1];

    fd = read(STDIN_FILENO, line, LINE_READ);
    if (fd >= LINE_READ) {
        my_ferror("./mysh: command too big");
        exit (SUCCESS);
    }
    line[fd - 1] = 0;
    exec_tree(line, env);
    return (SUCCESS);
}