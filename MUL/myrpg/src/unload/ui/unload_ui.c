/*
** EPITECH PROJECT, 2021
** unload_ui.c
** File description:
** unload_ui.c
*/

#include "my_rpg.h"

void unload_button(button_s but)
{
    sfText_destroy(but.text);
    sfFont_destroy(but.font);
}

void unload_menu_ui(menu_ui ui)
{
    sfText_destroy(ui.title);
    sfText_destroy(ui.htp.move);
    sfText_destroy(ui.htp.op_menu);
    sfText_destroy(ui.htp.navigate);
    sfFont_destroy(ui.title_font);
    sfFont_destroy(ui.htp.txt_font);
    unload_button(ui.play);
    unload_button(ui.quit);
    unload_button(ui.how_to_play);
    unload_button(ui.htp.back);
}

void unload_game_ui(game_ui ui)
{
    sfRectangleShape_destroy(ui.backg.shape);
    sfRectangleShape_destroy(ui.sound_menu.bg_shape);
    unload_button(ui.menu);
    unload_button(ui.sound);
    unload_button(ui.resume);
    unload_button(ui.quit);
    unload_button(ui.sound_menu.minus_music);
    unload_button(ui.sound_menu.plus_music);
    unload_button(ui.sound_menu.plus_effects);
    unload_button(ui.sound_menu.minus_effects);
    unload_button(ui.sound_menu.back);
}

void unload_ui(interface_s ui)
{
    unload_menu_ui(ui.menu);
    unload_game_ui(ui.game);
}