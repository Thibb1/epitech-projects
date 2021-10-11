/*
** EPITECH PROJECT, 2020
** events.c
** File description:
** common functions used to handle events CSFLM
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

void check_event(game_data *g)
{
    while (sfRenderWindow_pollEvent(g->render, &g->ev)) {
        if (g->ev.type == sfEvtClosed)
            sfRenderWindow_close(g->render);
        if (g->ev.type == sfEvtKeyPressed)
            check_key(g, g->ev.key);
    }
}