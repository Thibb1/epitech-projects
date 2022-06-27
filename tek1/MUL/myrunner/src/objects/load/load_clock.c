/*
** EPITECH PROJECT, 2020
** load_clock.c
** File description:
** clock loading
*/

#include "../../../include/my.h"
#include "../../../include/my_sfml.h"

int load_clock(game_data *game)
{
    game->clock = sfClock_create();
    if (game->clock)
        return (SUCCESS);
    return (ERROR);
}