/*
** EPITECH PROJECT, 2020
** load_settings.c
** File description:
** load settings saved or default
*/

#include "defender.h"

void get_settings(window *win, int fd)
{
    my_fscanf(fd, "%d%d", &win->tg.music, &win->tg.sounds);
}

void load_settings(window *win)
{
    int fd = open("assets/settings.data", O_RDONLY);

    if (fd == -1) {
        win->tg.music = 1;
        win->tg.sounds = 1;
    } else {
        get_settings(win, fd);
        close(fd);
    }
    win->fps = 30;
    win->vm.width = 1920;
    win->vm.height = 1080;
    win->vm.bitsPerPixel = 32;
    win->state = 0;
}
