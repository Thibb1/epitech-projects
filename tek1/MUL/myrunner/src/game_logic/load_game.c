/*
** EPITECH PROJECT, 2020
** load_game.c
** File description:
** game loading
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

int load_game(game_data *game, game_window *window, char *path)
{
    obstacle o;
    if (load_calls(game, window, path, &o)) {
        unload_game(game, window, &o);
        return (ERROR);
    }
    sfMusic_play(window->music);
    sfMusic_setLoop(window->music, sfTrue);
    while (sfRenderWindow_isOpen(game->render)) {
        game_loop(game, &o);
    }
    sfMusic_stop(window->music);
    unload_game(game, window, &o);
    return (SUCCESS);
}