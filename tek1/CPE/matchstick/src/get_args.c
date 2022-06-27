/*
** EPITECH PROJECT, 2020
** get_args.c
** File description:
** file check and args getter
*/

#include "match.h"

int only_num(const char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (FAILURE);
    return (SUCCESS);
}

int get_args(settings *a, int ac, const char *av[])
{
    if (ac != 3)
        return (my_ferror("./matchstick: Wrong number of args"));
    if (only_num(av[1]) || only_num(av[2]))
        return (my_ferror("./matchstick: Args should be positive intergers"));
    a->li = my_getnbr(av[1]);
    a->p = my_getnbr(av[2]);
    if (a->li <= 0 || a->p <= 0)
        return (my_ferror("./matchstick: Args should be positive intergers"));
    if (a->li > 100)
        return (my_ferror("./matchstick: n should be < 100"));
    return (SUCCESS);
}