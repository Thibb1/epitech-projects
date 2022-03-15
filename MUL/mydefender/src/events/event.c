/*
** EPITECH PROJECT, 2020
** event.c
** File description:
** basic user input functions
*/

#include "defender.h"

void check_mouse_movement(assets *as, window *win, sfMouseMoveEvent mouse)
{
    for (int i = 0; i < win->scenes[win->scene].nb_but; i++)
        is_hover(mouse, &win->scenes[win->scene].but[i]);
    if (win->scene == LVL) {
        check_hover(mouse, as);
        for (int i = 0; i < 4; i++)
            is_hover(mouse, &win->scenes[LVL].sh->but[i]);
    }
}

void check_key(assets *as, window *win, sfKeyEvent key)
{
    if ((win->scene == PAUSE || win->scene == LVL) &&
        key.code == sfKeyEscape) {
        win->scene = win->scene == PAUSE ? LVL : PAUSE;
        sfClock_restart(as->timer);
    }
}

void get_userinput(window *win, assets *as)
{
    if (win->ev.type == sfEvtClosed)
        sfRenderWindow_close(win->rw);
    if (win->ev.type == sfEvtMouseButtonPressed)
        check_click(win, win->ev.mouseButton, as);
    if (win->ev.type == sfEvtKeyPressed)
        check_key(as, win, win->ev.key);
    if (win->ev.type == sfEvtMouseMoved)
        check_mouse_movement(as, win, win->ev.mouseMove);
    if (!sfRenderWindow_hasFocus(win->rw) && win->scene == LVL)
        win->scene = PAUSE;
}
