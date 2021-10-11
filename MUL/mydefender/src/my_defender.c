/*
** EPITECH PROJECT, 2020
** my_defender.c
** File description:
** basic routine to start the app
*/

#include "defender.h"

int my_defender(void)
{
    window win;
    assets game = load_game(&win);

    win.scenes = game.scenes;
    while (sfRenderWindow_isOpen(win.rw)) {
        sfRenderWindow_clear(win.rw, win.bg);
        main_loop(&win, &game);
        sfRenderWindow_display(win.rw);
    }
    save_and_close(&win, &game);
    return (SUCCESS);
}