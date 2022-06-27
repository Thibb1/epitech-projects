/*
** EPITECH PROJECT, 2020
** list.c
** File description:
** init chained list
*/

#include "defender.h"

void set_tower(tower *cur, sfColor c, sfVector2f pos, int type)
{
    cur->level = 1;
    cur->type = type;
    cur->pos = pos;
    cur->state = B_IDLE;
    cur->shape = sfCircleShape_create();
    cur->outshape = sfCircleShape_create();
    cur->radius = sfCircleShape_create();
    cur->range = log(type * 20) * 100;
    if (type != E_CIRCLE)
        sfCircleShape_setPointCount(cur->shape, type);
    sfCircleShape_setOutlineThickness(cur->radius, 5);
    sfCircleShape_setOutlineColor(cur->radius, sfMagenta);
    sfCircleShape_setFillColor(cur->radius, sfTransparent);
    sfCircleShape_setFillColor(cur->shape, sfWhite);
    sfCircleShape_setRadius(cur->shape, 15);
    sfCircleShape_setFillColor(cur->outshape, c);
    sfCircleShape_setRadius(cur->outshape, 30);
    sfCircleShape_setPosition(cur->outshape, pos);
    pos = (sfVector2f) {pos.x + 15, pos.y + 15};
    sfCircleShape_setPosition(cur->shape, pos);
}
