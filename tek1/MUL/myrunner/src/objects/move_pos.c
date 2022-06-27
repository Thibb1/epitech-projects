/*
** EPITECH PROJECT, 2020
** move_pos.c
** File description:
** position movetings
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

void move_poss(sfVector2f *old_position, sfSprite *sprite, float x, float y)
{
    sfVector2f offset = {x, y};

    sfSprite_move(sprite, offset);
    *old_position = sfSprite_getPosition(sprite);
}