/*
** EPITECH PROJECT, 2020
** move_pos.c
** File description:
** position movetings
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

void update_render(game_data *game, obstacle *o)
{
    sfRenderWindow_clear(game->render, sfBlack);
    render_sprite(game->render, &game->ob, game, o);
    render_text(game->render, game->ob, game);
    sfRenderWindow_display(game->render);
}