/*
** EPITECH PROJECT, 2020
** unload_window.c
** File description:
** window unloading
*/

#include "../../../include/my.h"
#include "../../../include/my_sfml.h"

void unload_window(sfRenderWindow *window, sfMusic *music)
{
    sfMusic_destroy(music);
    sfRenderWindow_destroy(window);
}