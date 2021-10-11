/*
** EPITECH PROJECT, 2020
** move_bg.c
** File description:
** move the background
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

void move_bg(game_data *game, objects *ob)
{
    move_poss(&ob->bg[0].position, ob->bg[0].sprite, -100.f * game->elapsed, 0);
    move_poss(&ob->bg[1].position, ob->bg[1].sprite, -25.f * game->elapsed, 0);
    for (int i = 0; i < BG_NB - 1; i++)
        if (game->ob.bg[i].position.x < -1920)
            set_poss(&ob->bg[i].position, ob->bg[i].sprite, 0, 0);
}