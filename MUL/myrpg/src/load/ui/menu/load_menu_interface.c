/*
** EPITECH PROJECT, 2021
** load_menu_interface.c
** File description:
** load_menu_interface.c
*/

#include "my_rpg.h"

void set_title(menu_ui *menu)
{
    sfFloatRect rect;

    menu->title = sfText_create();
    menu->title_font = sfFont_createFromFile("./assets/poke_font/solid.ttf");
    sfText_setFont(menu->title, menu->title_font);
    sfText_setCharacterSize(menu->title, 200);
    sfText_setString(menu->title, "Pokemon");
    rect = sfText_getLocalBounds(menu->title);
    sfText_setPosition(menu->title, (sfVector2f)
    {(1920 / 2) - (rect.width / 2), 50});
    sfText_setColor(menu->title, (sfColor){230, 230, 0, 255});
    sfText_setOutlineThickness(menu->title, 10);
    sfText_setOutlineColor(menu->title, (sfColor){30, 0, 180, 255});
}

void load_menu_interface(menu_ui *menu)
{
    set_title(menu);
    set_play_button(&menu->play);
    set_how_to_play_button(&menu->how_to_play);
    set_quit_button(&menu->quit);
    menu->htp.move = sfText_create();
    menu->htp.op_menu = sfText_create();
    menu->htp.navigate = sfText_create();
    menu->htp.skip = sfText_create();
    set_htp_background(&menu->htp);
    set_htp_texts(&menu->htp);
    set_htp_back_button(&menu->htp.back);
    menu->disp_htp = sfFalse;
}