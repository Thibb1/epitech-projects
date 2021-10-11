/*
** EPITECH PROJECT, 2020
** move_bg.c
** File description:
** move the background
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

void move_obstacle(game_data *game, obstacle *o)
{
    float speed = -100.f * game->score;
    sfVector2f offset = {speed * game->elapsed, 0.f};

    for (int i = o->ob_left; i < game->ob_nb; i++) {
            sfSprite_move(o->o[i].sprite, offset);
            o->o[i].position = sfSprite_getPosition(o->o[i].sprite);
    }
    for (int i = o->ob_left; i < game->ob_nb; i++)
        if (o->o[i].position.x < -200) {
            sfSprite_destroy(o->o[i].sprite);
            sfTexture_destroy(o->o[i].texture);
            o->ob_left++;
        }
}