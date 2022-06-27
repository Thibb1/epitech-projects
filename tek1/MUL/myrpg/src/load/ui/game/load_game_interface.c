/*
** EPITECH PROJECT, 2021
** load_game_interface.c
** File description:
** load_game_interface.c
*/

#include "my_rpg.h"

void load_start_menu_bg(s_m_bg *bg)
{
    bg->shape = sfRectangleShape_create();
    bg->color = sfWhite;
    bg->outline = (sfColor){96, 38, 96, 255};
    bg->pos = (sfVector2f){1380, 35};
    bg->size = (sfVector2f){500, 420};
    sfRectangleShape_setFillColor(bg->shape, bg->color);
    sfRectangleShape_setOutlineThickness(bg->shape, 10);
    sfRectangleShape_setOutlineColor(bg->shape, bg->outline);
    sfRectangleShape_setPosition(bg->shape, bg->pos);
    sfRectangleShape_setSize(bg->shape, bg->size);
}

void load_game_interface(game_ui *game)
{
    load_start_menu_bg(&game->backg);
    game->dis_s_menu = sfFalse;
    load_sound_menu(&game->sound_menu);
    load_game_sound(&game->sound);
    load_game_resume(&game->resume);
    load_game_menu(&game->menu);
    load_game_quit(&game->quit);
}