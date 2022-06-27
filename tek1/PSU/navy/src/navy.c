/*
** EPITECH PROJECT, 2020
** navy.c
** File description:
** navy game
*/

#include "../include/my.h"
#include "../include/navy.h"

int main(int ac, char *av[])
{
    net pids = {ac == 3 ? my_getnbr(av[1]) : getpid(), ac == 3 ? getpid() : 0,
        ac == 3 ? 0 : 1};
    char map[2][8][8];
    if (check_av(ac, av) == 84)
        return (84);
    if (check_help(ac, av))
        return (0);
    if (load_map(ac == 2 ? av[1] : av[2], map))
        return (84);
    connect_process(&pids);
    return (game(pids, map));
}