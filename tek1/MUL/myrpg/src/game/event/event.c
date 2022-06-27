/*
** EPITECH PROJECT, 2021
** event.c
** File description:
** event.c
*/

#include "my_rpg.h"

void player_dir(player_s *p, sfKeyEvent key)
{
    int dir = p->dir;
    if (key.code == sfKeyUp && dir == 0) {
        p->dir = 1;
        p->released = 0;
    }
    if (key.code == sfKeyDown && dir == 0) {
        p->dir = 2;
        p->released = 0;
    }
    if (key.code == sfKeyLeft && dir == 0) {
        p->dir = 3;
        p->released = 0;
    }
    if (key.code == sfKeyRight && dir == 0) {
        p->dir = 4;
        p->released = 0;
    }
}

void release_player_dir(player_s *p, sfKeyEvent key)
{
    int dir = p->dir;

    if (key.code == sfKeyUp && dir == 1)
        p->released = 1;
    if (key.code == sfKeyDown && dir == 2)
        p->released = 1;
    if (key.code == sfKeyLeft && dir == 3)
        p->released = 1;
    if (key.code == sfKeyRight && dir == 4)
        p->released = 1;
}

void press_x_quest(my_rpg *rpg, int state)
{
    if (state == 1 || state == 2 || state == 4)
        rpg->quest.state++;
}

void analyse_event(my_rpg *rpg, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->r.w);
    ui_event(rpg, event);
    if (event.type == sfEvtKeyReleased)
        release_player_dir(&rpg->player, event.key);
    if (rpg->mode == 1 && event.type == sfEvtKeyPressed)
        if (rpg->player.dir == 0)
            player_dir(&rpg->player, event.key);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyX)
        press_x_quest(rpg, rpg->quest.state);
}
