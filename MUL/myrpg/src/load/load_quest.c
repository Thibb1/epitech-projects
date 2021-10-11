/*
** EPITECH PROJECT, 2020
** load_window.c
** File description:
** loads window
*/

#include "my_rpg.h"

void load_quest_txt2(quest_s *q)
{
    sfFloatRect rect;

    sfText_setOutlineThickness(q->text1, 5);
    sfText_setOutlineThickness(q->text2, 5);
    sfText_setOutlineThickness(q->text3, 5);
    sfText_setCharacterSize(q->text1, 50);
    sfText_setCharacterSize(q->text2, 50);
    sfText_setCharacterSize(q->text3, 50);
    rect = sfText_getLocalBounds(q->text1);
    sfText_setPosition(q->text1, (sfVector2f){960 - (rect.width / 2), 830});
    rect = sfText_getLocalBounds(q->text2);
    sfText_setPosition(q->text2, (sfVector2f){960 - (rect.width / 2), 930});
    rect = sfText_getLocalBounds(q->text3);
    sfText_setPosition(q->text3, (sfVector2f){960 - (rect.width / 2), 830});
}

void load_quest_txt(quest_s *q)
{
    q->state = 0;
    q->text1 = sfText_create();
    q->text2 = sfText_create();
    q->text3 = sfText_create();
    q->font = sfFont_createFromFile("./assets/poke_font/solid.ttf");
    sfText_setString(q->text1, "Hey there! If you want to pass, go walk");
    sfText_setString(q->text2, "in the tall grass, and fight a pokemon!");
    sfText_setString(q->text3, "Nice fight! You can pass now.");
    sfText_setFont(q->text1, q->font);
    sfText_setFont(q->text2, q->font);
    sfText_setFont(q->text3, q->font);
    sfText_setColor(q->text1, (sfColor){230, 230, 0, 255});
    sfText_setColor(q->text2, (sfColor){230, 230, 0, 255});
    sfText_setColor(q->text3, (sfColor){230, 230, 0, 255});
    sfText_setOutlineColor(q->text1, (sfColor){30, 0, 180, 255});
    sfText_setOutlineColor(q->text2, (sfColor){30, 0, 180, 255});
    sfText_setOutlineColor(q->text3, (sfColor){30, 0, 180, 255});
    load_quest_txt2(q);
}

void load_quest2(quest_s *q)
{
    q->clock = sfClock_create();
    q->textbox = sfRectangleShape_create();
    q->texture = sfTexture_createFromFile("assets/game/pnj-quest.png", NULL);
    q->sprite = sfSprite_create();
    sfSprite_setTexture(q->sprite, q->texture, sfFalse);
    sfSprite_setPosition(q->sprite, (sfVector2f){39 * 64 - 16, 23 * 64 + 16});
    sfSprite_setScale(q->sprite, (sfVector2f){3, 3});
    sfRectangleShape_setPosition(q->textbox, (sfVector2f){0, 810});
    sfRectangleShape_setOutlineColor(q->textbox, (sfColor){96, 38, 96, 255});
    sfRectangleShape_setOutlineThickness(q->textbox, 4);
    sfRectangleShape_setSize(q->textbox, (sfVector2f){1920, 270});
}