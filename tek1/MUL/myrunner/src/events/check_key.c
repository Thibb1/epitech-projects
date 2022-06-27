/*
** EPITECH PROJECT, 2020
** events.c
** File description:
** common fonctions used to handle events CSFLM
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

void check_key(game_data *g, sfKeyEvent kevent)
{
    if (kevent.code == sfKeyEscape)
        sfRenderWindow_close(g->render);
    if (g->ob.player.grounded && kevent.code == sfKeySpace &&
        g->ob.player.state != JUMP) {
        g->ob.player.current_sprite = 0;
        g->ob.player.state = JUMP;
        g->ob.player.grounded = 0;
    }
    if (kevent.code == sfKeyP && g->state != WIN && g->state != LOOSE)
        g->state = g->state != LEVEL_MODE ? LEVEL_MODE : MENU;
}
