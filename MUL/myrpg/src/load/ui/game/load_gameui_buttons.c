/*
** EPITECH PROJECT, 2021
** load_gameui_buttons.c
** File description:
** load_gameui_buttons.c
*/

#include "my_rpg.h"

void load_game_sound(button_s *button)
{
    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/solid.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 70);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "Sound");
    sfText_setPosition(button->text, (sfVector2f){1400, 50});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 5);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}

void load_game_resume(button_s *button)
{
    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/solid.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 70);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "Resume");
    sfText_setPosition(button->text, (sfVector2f){1400, 150});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 5);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}

void load_game_menu(button_s *button)
{
    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/solid.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 70);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "Menu");
    sfText_setPosition(button->text, (sfVector2f){1400, 250});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 5);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}

void load_game_quit(button_s *button)
{
    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/solid.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 70);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "Quit");
    sfText_setPosition(button->text, (sfVector2f){1400, 350});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 5);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}