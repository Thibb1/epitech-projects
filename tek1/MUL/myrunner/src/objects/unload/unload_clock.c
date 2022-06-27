/*
** EPITECH PROJECT, 2020
** unload_clock.c
** File description:
** clock unloading
*/

#include "../../../include/my.h"
#include "../../../include/my_sfml.h"

void unload_clock(game_data *game)
{
    sfClock_destroy(game->clock);
}