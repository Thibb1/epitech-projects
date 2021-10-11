/*
** EPITECH PROJECT, 2020
** load_game.c
** File description:
** load basic info and assets to run the game
*/

#include "defender.h"

assets load_game(window *win)
{
    assets as;
    sfColor a = {35, 35, 35, 1};

    load_settings(win);
    load_score(&as);
    load_assets(&as);
    win->rw = sfRenderWindow_create(win->vm, "Defender", sfFullscreen |
        sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win->rw, win->fps);
    win->bg = a;
    win->scene = 0;
    win->launched = 0;
    return (as);
}

void create_duck(duck *daffyduck)
{
    daffyduck->sprite_duck = sfSprite_create();
    daffyduck->texture_duck = sfTexture_createFromFile("assets/Idle.png", NULL);
    daffyduck->position.x = 1140;
    daffyduck->position.y = 270;
    daffyduck->rect.top = 0;
    daffyduck->rect.left = 0;
    daffyduck->rect.height = 110;
    daffyduck->rect.width = 110;
    daffyduck->duck_state = 0;
}