/*
** EPITECH PROJECT, 2020
** av_parse.c
** File description:
** parse input and file
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

int av_parse(char *av[])
{
    if (!my_strcmp(av[1], "-h")) {
        print_help();
        return (HELP_MODE);
    } else if (!my_strcmp(av[1], "-i")) {
        return (INFINITE_MODE);
    } else
        if (file_check(av[1]) == ERROR) {
            my_printf("%s: can't open %s\n", av[0], av[1]);
            return (ERROR);
        }
    return (LEVEL_MODE);
}