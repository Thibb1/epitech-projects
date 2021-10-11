/*
** EPITECH PROJECT, 2020
** unload_game.c
** File description:
** game unloading
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

void unload_ob(game_data *game, obstacle *o)
{
    for (int i = o->ob_left; i < game->ob_nb; i++) {
        sfSprite_destroy(o->o[i].sprite);
        sfTexture_destroy(o->o[i].texture);
    }
}

void unload_game(game_data *game, game_window *window, obstacle *o)
{
    unload_audio(game->ob);
    unload_clock(game);
    unload_sprites(game->ob);
    unload_text(game->ob);
    unload_ob(game, o);
    unload_window(game->render, window->music);
}