/*
** EPITECH PROJECT, 2020
** input.c
** File description:
** sh funct
*/

#include "my_sh.h"


int user_shell(char **env)
{
    int fd;
    char line[LINE_READ + 1];

    prompt(STARTUP, env);
    prompt(RUNNING, env);
    while ((fd = read(STDIN_FILENO, line, LINE_READ)) > 0) {
        if (fd >= LINE_READ) {
            my_ferror("./mysh: command too big");
            exit (SUCCESS);
        }
        line[fd - 1] = 0;
        exec_tree(line, env);
        for (int len = 0; len <= LINE_READ; len++)
            line[len] = 0;
        prompt(RUNNING, env);
    }
    close(fd);
    return (SUCCESS);
}