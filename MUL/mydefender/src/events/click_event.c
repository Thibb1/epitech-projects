/*
** EPITECH PROJECT, 2021
** click_event.c
** File description:
** click_event.c
*/

#include "defender.h"

void click_menu(window *win, scene scenes)
{
    if (scenes.but[0].state == B_CLICKED) {
        scenes.but[0].state = B_IDLE;
        win->scene = 1;
        win->launched = 1;
    }
    if (scenes.but[1].state == B_CLICKED) {
        scenes.but[1].state = B_IDLE;
        sfRenderWindow_close(win->rw);
    }
}

void click_pause(window *win, scene scenes, assets *as)
{
    if (scenes.but[0].state == B_CLICKED) {
        scenes.but[0].state = B_IDLE;
        sfClock_restart(as->timer);
        win->scene = LVL;
    }
    if (scenes.but[1].state == B_CLICKED) {
        scenes.but[1].state = B_IDLE;
        win->scene = MENU;
    }
    if (scenes.but[2].state == B_CLICKED) {
        scenes.but[2].state = B_IDLE;
        sfRenderWindow_close(win->rw);
    }
}

void check_click(window *win, sfMouseButtonEvent click, assets *as)
{
    for (int i = 0; i < win->scenes[win->scene].nb_but; i++)
        is_clicked(click, &win->scenes[win->scene].but[i]);
    if (win->scene == MENU)
        click_menu(win, win->scenes[MENU]);
    if (win->scene == LVL) {
        click_tower(win, click, as);
        click_lvl(click, win, win->scenes[LVL].sh, as);
        check_lvl(win->scenes[LVL].sh);
    }
    if (win->scene == PAUSE)
        click_pause(win, win->scenes[PAUSE], as);
}
