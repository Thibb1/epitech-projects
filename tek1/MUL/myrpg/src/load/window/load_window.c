/*
** EPITECH PROJECT, 2020
** load_window.c
** File description:
** loads window
*/

#include "my_rpg.h"

void load_window(render *ren)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    char *title = "Pokemon Version Mewtwo";

    ren->w = sfRenderWindow_create(mode, title, sfClose | sfFullscreen, NULL);
    ren->t = sfRenderTexture_create(mode.width, mode.height, sfFalse);
    ren->t_sprite = sfSprite_create();
    sfSprite_setTexture(ren->t_sprite, sfRenderTexture_getTexture(ren->t),
        sfTrue);
    sfRenderWindow_setFramerateLimit(ren->w, 120);
}