/*
** EPITECH PROJECT, 2020
** load_score.c
** File description:
** load score saved or default
*/

#include "defender.h"

void get_score(assets *as, int fd)
{
    my_fscanf(fd, "%d%d", &as->gs.t_coins, &as->gs.t_enemies);
    my_fscanf(fd, "%d%d", &as->gs.t_waves, &as->gs.t_towers);
    my_fscanf(fd, "%d%d", &as->gs.t_time, &as->gs.b_score);
}

void load_score(assets *as)
{
    int fd = open("assets/score.data", O_RDONLY);

    if (fd == -1) {
        as->gs.t_coins = 0;
        as->gs.t_enemies = 0;
        as->gs.t_waves = 0;
        as->gs.t_towers = 0;
        as->gs.t_time = 0;
        as->gs.b_score = 0;
    } else {
        get_score(as, fd);
        close(fd);
    }
}
