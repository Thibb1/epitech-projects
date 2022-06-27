/*
** EPITECH PROJECT, 2020
** av_check.c
** File description:
** check input and file
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

int av_check(int ac, char *av[])
{
    if (ac == 2)
        return (SUCCESS);
    my_printf("%s: wrong number of arguments: %d given but 1 ", av[0], ac - 1);
    my_printf("is required\nretry with -h\n");
    return (ERROR);
}