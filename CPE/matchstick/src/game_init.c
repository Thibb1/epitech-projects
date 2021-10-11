/*
** EPITECH PROJECT, 2020
** game_init.c
** File description:
** init game data
*/

#include "match.h"

int *init_sticks(settings *a)
{
    int *sticks = malloc(sizeof(int) * a->li);
    a->nim_arr = malloc(sizeof(int) * a->li);

    for (int i = 0; i < a->li; i++) {
        sticks[i] = (i + 1) + i % (i + 1);
        a->n += sticks[i];
    }
    a->width = sticks[a->li - 1] + 2;
    return (sticks);
}

int game_init(settings a)
{
    int *sticks = init_sticks(&a);
    int ret = game_loop(a, sticks);

    free(sticks);
    free(a.nim_arr);
    return (ret);
}