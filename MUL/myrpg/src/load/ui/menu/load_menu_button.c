/*
** EPITECH PROJECT, 2021
** load_menu_button.c
** File description:
** load_menu_button.c
*/

#include "my_rpg.h"

void set_play_button(button_s *button)
{
    sfFloatRect rect;

    button->type = TEXT_ONLY;
    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/hollow.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 100);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "Play");
    rect = sfText_getLocalBounds(button->text);
    sfText_setPosition(button->text,
        (sfVector2f){(1920 / 2) - (rect.width / 2), 400});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 5);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}

void set_quit_button(button_s *button)
{
    sfFloatRect rect;

    button->type = TEXT_ONLY;
    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/hollow.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 100);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "Quit");
    rect = sfText_getLocalBounds(button->text);
    sfText_setPosition(button->text,
        (sfVector2f) {(1920 / 2) - (rect.width / 2), 800});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 5);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}

void set_how_to_play_button(button_s *button)
{
    sfFloatRect rect;

    button->type = TEXT_ONLY;
    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/hollow.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 100);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "How to play");
    rect = sfText_getLocalBounds(button->text);
    sfText_setPosition(button->text,
        (sfVector2f) {(1920 / 2) - (rect.width / 2), 600});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 5);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}