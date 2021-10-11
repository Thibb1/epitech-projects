/*
** EPITECH PROJECT, 2020
** game_loop.c
** File description:
** main game loop
*/

#include "match.h"

int calc_n(settings *a, int *sticks)
{
    int n = 0;

    for (int i = 0; i < a->li; i++)
        n += sticks[i];
    return (n);
}

int game_loop(settings a, int *sticks)
{
    int ret = -1;
    a.n = calc_n(&a, sticks);

    while (ret == -1) {
        print_sticks(&a, sticks);
        ret = user_input(&a, sticks);
        if (ret != -1)
            break;
        print_sticks(&a, sticks);
        ret = ia_input(&a, sticks);
    }
    return (ret);
}