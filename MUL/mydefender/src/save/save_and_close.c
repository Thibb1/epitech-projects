/*
** EPITECH PROJECT, 2020
** save_and_close.c
** File description:
** basic routine to stop and save the app
*/

#include "defender.h"

void save_settings(window *win)
{
    int fd;

    create_file("assets/settings.data");
    fd = open("assets/settings.data", O_WRONLY);
    if (fd != -1) {
        my_dprintf(fd, "%d %d\n", win->tg.music, win->tg.sounds);
        close(fd);
    }
}

void save_score(assets *as)
{
    int fd;

    create_file("assets/score.data");
    fd = open("assets/score.data", O_WRONLY);
    as->gs.t_time += as->current_s;
    if (fd != -1) {
        my_dprintf(fd, "%d %d\n", as->gs.t_coins, as->gs.t_enemies);
        my_dprintf(fd, "%d %d\n", as->gs.t_waves, as->gs.t_towers);
        my_dprintf(fd, "%d %d\n", as->gs.t_time, as->gs.b_score);
        close(fd);
    }
}

void save_and_close(window *win, assets *as)
{
    remove_lists(as);
    remove_pops(as);
    save_settings(win);
    save_score(as);
    unload_game(win, as);
}
