/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** calls my functions
*/

#include "../include/my.h"
#include "../include/ls.h"

int main(int ac, char *av[])
{
    ls_s flags = get_flag(ac, av);

    process_path(flags);
    for (int i = 0; i < flags.path; i++)
        free(flags.pathname[i]);
    free(flags.pathname);
    return (0);
}
