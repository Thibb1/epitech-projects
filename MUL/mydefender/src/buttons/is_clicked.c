/*
** EPITECH PROJECT, 2020
** is_clicked.c
** File description:
** button is clicked and is hover funct
*/

#include "defender.h"

void is_clicked(sfMouseButtonEvent click, button *b)
{
    if (click.x >= b->pos.x && click.x <= (b->pos.x + b->size.x)
        && click.y >= b->pos.y && click.y <= (b->pos.y + b->size.y))
        if (b->state != B_DISABLE)
            b->state = B_CLICKED;
}

void is_hover(sfMouseMoveEvent mouse, button *b)
{
    if (mouse.x >= b->pos.x && mouse.x <= (b->pos.x + b->size.x)
        && mouse.y >= b->pos.y && mouse.y <= (b->pos.y + b->size.y)) {
        if (b->state != B_CLICKED && b->state != B_DISABLE) {
            b->state = B_HOVER;
            b->color.a = 224;
        }
    } else if (b->state == B_HOVER) {
        b->state = B_IDLE;
        b->color.a = 255;
    }
    sfRectangleShape_setFillColor(b->rect, b->color);
}