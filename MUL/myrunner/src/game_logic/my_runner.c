/*
** EPITECH PROJECT, 2020
** my_runner.c
** File description:
** game calls and checking
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

int my_runner(int ac, char *av[])
{
    game_data game;
    game_window window;

    if (av_check(ac, av))
        return (ERROR);
    game.state = av_parse(av);
    if (game.state == LEVEL_MODE)
        return (load_game(&game, &window, av[1]));
    else if (game.state == INFINITE_MODE)
        return (load_game(&game, &window, "assets/map_i.txt"));
    if (game.state == ERROR)
        return (ERROR);
    return (SUCCESS);
}