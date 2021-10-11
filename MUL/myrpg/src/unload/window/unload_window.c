/*
** EPITECH PROJECT, 2020
** unload_window.c
** File description:
** unloads window
*/

#include "my_rpg.h"

void unload_window(render r)
{
    sfRenderTexture_destroy(r.t);
    sfRenderWindow_destroy(r.w);
}