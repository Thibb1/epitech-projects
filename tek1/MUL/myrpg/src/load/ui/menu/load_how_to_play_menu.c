/*
** EPITECH PROJECT, 2021
** load_how_to_play_menu.c
** File description:
** load_how_to_play_menu.c
*/

#include "my_rpg.h"

void set_htp_background(htp_menu *menu)
{
    menu->bg = sfRectangleShape_create();
    sfRectangleShape_setSize(menu->bg, (sfVector2f){1000, 600});
    sfRectangleShape_setFillColor(menu->bg, (sfColor){230, 60, 40, 255});
    sfRectangleShape_setOrigin(menu->bg, (sfVector2f){500, 350});
    sfRectangleShape_setPosition(menu->bg, (sfVector2f){960, 770});
}

void set_htp_texts_suite(htp_menu *menu)
{
    sfFloatRect rect;

    sfText_setOutlineColor(menu->move, (sfColor){30, 0, 180, 255});
    sfText_setOutlineColor(menu->op_menu, (sfColor){30, 0, 180, 255});
    sfText_setOutlineColor(menu->navigate, (sfColor){30, 0, 180, 255});
    sfText_setOutlineColor(menu->skip, (sfColor){30, 0, 180, 255});
    sfText_setCharacterSize(menu->move, 40);
    sfText_setCharacterSize(menu->op_menu, 40);
    sfText_setCharacterSize(menu->navigate, 40);
    sfText_setCharacterSize(menu->skip, 40);
    rect = sfText_getLocalBounds(menu->move);
    sfText_setPosition(menu->move, (sfVector2f){960 - rect.width / 2, 480});
    rect = sfText_getLocalBounds(menu->op_menu);
    sfText_setPosition(menu->op_menu, (sfVector2f){960 - rect.width / 2, 580});
    rect = sfText_getLocalBounds(menu->navigate);
    sfText_setPosition(menu->navigate,
    (sfVector2f){960 - rect.width / 2, 680});
    rect = sfText_getLocalBounds(menu->skip);
    sfText_setPosition(menu->skip, (sfVector2f){960 - rect.width / 2, 780});
}

void set_htp_texts(htp_menu *menu)
{
    menu->txt_font = sfFont_createFromFile("./assets/poke_font/solid.ttf");
    sfText_setFont(menu->move, menu->txt_font);
    sfText_setFont(menu->op_menu, menu->txt_font);
    sfText_setFont(menu->navigate, menu->txt_font);
    sfText_setFont(menu->skip, menu->txt_font);
    sfText_setString(menu->move, "Use arrows to move around");
    sfText_setString(menu->op_menu, "Use 'Escape' to open the menu");
    sfText_setString(menu->navigate, "Use the mouse to navigate in the menus");
    sfText_setString(menu->skip, "Use 'X' to skip dialogs");
    sfText_setColor(menu->move, (sfColor){230, 230, 0, 255});
    sfText_setColor(menu->op_menu, (sfColor){230, 230, 0, 255});
    sfText_setColor(menu->navigate, (sfColor){230, 230, 0, 255});
    sfText_setColor(menu->skip, (sfColor){230, 230, 0, 255});
    sfText_setOutlineThickness(menu->move, 5);
    sfText_setOutlineThickness(menu->op_menu, 5);
    sfText_setOutlineThickness(menu->navigate, 5);
    sfText_setOutlineThickness(menu->skip, 5);
    set_htp_texts_suite(menu);
}

void set_htp_back_button(button_s *button)
{
    sfFloatRect rect;

    button->state = IDLE;
    button->font = sfFont_createFromFile("./assets/poke_font/hollow.ttf");
    button->text = sfText_create();
    sfText_setCharacterSize(button->text, 100);
    sfText_setFont(button->text, button->font);
    sfText_setString(button->text, "Back");
    rect = sfText_getLocalBounds(button->text);
    sfText_setPosition(button->text, (sfVector2f){960 - (rect.width / 2), 860});
    sfText_setColor(button->text, sfWhite);
    sfText_setOutlineThickness(button->text, 5);
    sfText_setOutlineColor(button->text, (sfColor){30, 0, 180, 255});
    button->idle = sfWhite;
    button->hover = (sfColor){230, 230, 0, 255};
}