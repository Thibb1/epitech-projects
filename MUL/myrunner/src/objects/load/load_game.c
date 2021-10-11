/*
** EPITECH PROJECT, 2020
** load_window.c
** File description:
** window loading
*/

#include "../../../include/my.h"
#include "../../../include/my_sfml.h"

int load_window(game_data *game, game_window *window)
{
    sfVector2i zero = {0, 0};

    window->mode.width = 1920;
    window->mode.height = 1080;
    window->mode.bitsPerPixel = 32;
    window->music = sfMusic_createFromFile("assets/music.ogg");
    game->render = sfRenderWindow_create(window->mode, NAME, sfResize |
        sfClose, NULL);
    game->score = 1.f;
    sfRenderWindow_setFramerateLimit(game->render, 30);
    sfRenderWindow_setVerticalSyncEnabled(game->render, sfFalse);
    sfRenderWindow_setPosition(game->render, zero);
    if (window->music && game->render)
        return (SUCCESS);
    return (ERROR);
}