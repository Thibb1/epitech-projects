/*
** EPITECH PROJECT, 2020
** match.c
** File description:
** main logic
*/

#include "match.h"

int match(int ac, const char *av[])
{
    settings a = {0, 0, 0, 0, NULL};

    srand(time(NULL));
    if (get_args(&a, ac, av))
        return (FAILURE);
    return (game_init(a));
}