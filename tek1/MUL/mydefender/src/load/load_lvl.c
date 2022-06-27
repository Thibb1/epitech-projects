/*
** EPITECH PROJECT, 2020
** load_lvl.c
** File description:
** load basic info and assets to run the game
*/

#include "defender.h"

void load_lvl_pos(game *lvl)
{
    sfRectangleShape_setPosition(lvl->rect[0], (sfVector2f){0, 60});
    sfRectangleShape_setSize(lvl->rect[0], (sfVector2f){360, 60});
    sfRectangleShape_setPosition(lvl->rect[1], (sfVector2f){300, 120});
    sfRectangleShape_setSize(lvl->rect[1], (sfVector2f){60, 540});
    sfRectangleShape_setPosition(lvl->rect[2], (sfVector2f){120, 660});
    sfRectangleShape_setSize(lvl->rect[2], (sfVector2f){240, 60});
    sfRectangleShape_setPosition(lvl->rect[3], (sfVector2f){120, 720});
    sfRectangleShape_setSize(lvl->rect[3], (sfVector2f){60, 300});
    sfRectangleShape_setPosition(lvl->rect[4], (sfVector2f){180, 960});
    sfRectangleShape_setSize(lvl->rect[4], (sfVector2f){1020, 60});
    sfRectangleShape_setPosition(lvl->rect[5], (sfVector2f){1140, 660});
    sfRectangleShape_setSize(lvl->rect[5], (sfVector2f){60, 300});
    sfRectangleShape_setPosition(lvl->rect[6], (sfVector2f){780, 660});
    sfRectangleShape_setSize(lvl->rect[6], (sfVector2f){360, 60});
    sfRectangleShape_setPosition(lvl->rect[7], (sfVector2f){780, 300});
    sfRectangleShape_setSize(lvl->rect[7], (sfVector2f){60, 360});
    sfRectangleShape_setPosition(lvl->rect[8], (sfVector2f){840, 300});
    sfRectangleShape_setSize(lvl->rect[8], (sfVector2f){420, 60});
}

void load_lvl(game *lvl)
{
    sfColor primary = {90, 90, 90, 255};

    lvl->nb_cases = 10;
    lvl->rect = malloc(sizeof(sfRectangleShape *) * lvl->nb_cases);
    for (int i = 0; i < lvl->nb_cases; i++) {
        lvl->rect[i] = sfRectangleShape_create();
        sfRectangleShape_setFillColor(lvl->rect[i], primary);
    }
    sfRectangleShape_setFillColor(lvl->rect[9], sfCyan);
    sfRectangleShape_setPosition(lvl->rect[9], (sfVector2f){1140, 270});
    sfRectangleShape_setSize(lvl->rect[9], (sfVector2f){120, 120});
    load_lvl_pos(lvl);
}
