/*
** EPITECH PROJECT, 2020
** text.c
** File description:
** basic text component
*/

#include "defender.h"

void text_change_centered(text *text, char *str, sfVector2f pos)
{
    sfFloatRect rect_text;
    sfVector2f center;

    sfText_setString(text->text, str);
    rect_text = sfText_getLocalBounds(text->text);
    center.x = rect_text.width / 2.0;
    center.y = rect_text.height / 2.0;
    sfText_setOrigin(text->text, center);
    sfText_setPosition(text->text, pos);
    text->pos = pos;
}

void init_text(text *text, sfColor color, sfVector2f pos_fs[2], char *str)
{
    sfFont *font = sfFont_createFromFile("assets/ostrich-regular.ttf");

    text->text = sfText_create();
    text->color = color;
    if (pos_fs[1].y == 1)
        sfText_setStyle(text->text, sfTextBold);
    sfText_setCharacterSize(text->text, (int)pos_fs[1].x);
    sfText_setFont(text->text, font);
    text_change_centered(text, str, pos_fs[0]);
    sfText_setColor(text->text, color);
}
