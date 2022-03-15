/*
** EPITECH PROJECT, 2020
** button.c
** File description:
** basic button component
*/

#include "defender.h"

void init_base_button(button *button, sfVector2f size)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setOutlineThickness(button->rect, 10);
    button->state = B_IDLE;
    button->size = sfRectangleShape_getSize(button->rect);
}

void init_button(button *button, sfColor colors[2], sfVector2f pos_size[2],
    char *texture)
{
    init_base_button(button, pos_size[1]);

    if (texture != NULL) {
        button->texture = sfTexture_createFromFile(texture, NULL);
        sfRectangleShape_setTexture(button->rect, button->texture, sfTrue);
    }
    button->color = colors[0];
    button->outline = colors[1];
    sfRectangleShape_setPosition(button->rect, pos_size[0]);
    button->pos = sfRectangleShape_getPosition(button->rect);
    sfRectangleShape_setFillColor(button->rect, button->color);
    sfRectangleShape_setOutlineColor(button->rect, button->outline);
}
