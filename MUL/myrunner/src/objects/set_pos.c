/*
** EPITECH PROJECT, 2020
** set_pos.c
** File description:
** position settings
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

void set_post(sfText *text, float x, float y)
{
    sfVector2f position = {x, y};

    sfText_setPosition(text, position);
}

void set_poss(sfVector2f *old_position, sfSprite *sprite, float x, float y)
{
    sfVector2f position = {x, y};

    sfSprite_setPosition(sprite, position);
    *old_position = sfSprite_getPosition(sprite);
}