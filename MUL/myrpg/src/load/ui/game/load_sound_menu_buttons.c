/*
** EPITECH PROJECT, 2021
** load_sound_menu_buttons.c
** File description:
** load_sound_menu_buttons.c
*/

#include "my_rpg.h"

void load_minus_music(button_s *button)
{
    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/solid.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 80);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "-");
    sfText_setPosition(button->text, (sfVector2f){980, 420});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 3);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}

void load_plus_music(button_s *button)
{
    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/solid.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 80);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "+");
    sfText_setPosition(button->text, (sfVector2f){1180, 420});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 3);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}

void load_minus_effects(button_s *button)
{
    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/solid.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 90);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "-");
    sfText_setPosition(button->text, (sfVector2f){980, 570});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 3);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}

void load_plus_effects(button_s *button)
{
    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/solid.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 90);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "+");
    sfText_setPosition(button->text, (sfVector2f){1180, 570});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 3);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}

void load_back_button(button_s *button)
{
    sfFloatRect rect;

    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/solid.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 80);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "Back");
    rect = sfText_getLocalBounds(button->text);
    sfText_setPosition(button->text, (sfVector2f)
    {(1920 / 2) - (rect.width / 2), 680});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 3);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}