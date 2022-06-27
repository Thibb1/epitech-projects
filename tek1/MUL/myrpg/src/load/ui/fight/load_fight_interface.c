/*
** EPITECH PROJECT, 2021
** load_fight_interface.c
** File description:
** load_fight_interface.c
*/

#include "my_rpg.h"

void load_fight_text(fight_ui *fight)
{
    sfFont *font = sfFont_createFromFile("./assets/poke_font/solid.ttf");
    sfFloatRect rect;

    fight->text = sfText_create();
    sfText_setFont(fight->text, font);
    sfText_setString(fight->text, "Fight !!");
    sfText_setCharacterSize(fight->text, 100);
    sfText_setColor(fight->text, (sfColor){230, 230, 0, 255});
    sfText_setOutlineThickness(fight->text, 5);
    sfText_setOutlineColor(fight->text, (sfColor){30, 0, 180, 255});
    rect = sfText_getLocalBounds(fight->text);
    sfText_setPosition(fight->text, (sfVector2f){960 - (rect.width / 2), 480});
}

void load_fight_back_button(button_s *button)
{
    sfFloatRect rect;

    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/hollow.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 80);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "Back");
    rect = sfText_getLocalBounds(button->text);
    sfText_setPosition(button->text,
    (sfVector2f){960 - (rect.width / 2), 660});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 4);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}

void load_fight_interface(fight_ui *fight)
{
    fight->bg = sfRectangleShape_create();
    sfRectangleShape_setFillColor(fight->bg, sfWhite);
    sfRectangleShape_setOutlineThickness(fight->bg, 10);
    sfRectangleShape_setOutlineColor(fight->bg, (sfColor){96, 38, 96, 255});
    sfRectangleShape_setSize(fight->bg, (sfVector2f){600, 400});
    sfRectangleShape_setPosition(fight->bg, (sfVector2f){660, 390});
    load_fight_text(fight);
    load_fight_back_button(&fight->back);
}