/*
** EPITECH PROJECT, 2021
** click_event.c
** File description:
** click_event.c
*/

#include "defender.h"

void click_tower(window *win, sfMouseButtonEvent click, assets *as)
{
    tower *cur = as->t_head;
    sfVector2f pos = get_tower_placement(click);
    int n = 0;

    while (cur != NULL) {
        if (pos.x == cur->pos.x && pos.y == cur->pos.y) {
            cur->state = B_CLICKED;
            win->state = 0;
        }
        else if (click.x < 1255)
            cur->state = B_IDLE;
        if (click.x > 1255 && cur->state == B_CLICKED) {
            check_click_tower(click, as->scenes[LVL].sh[1]);
            if (check_tower_button(as->scenes[LVL].sh[1], cur, as))
                remove_tower(as, n--);
        }
        cur = cur->next;
        n++;
    }
}

void check_hover(sfMouseMoveEvent click, assets *as)
{
    tower *cur = as->t_head;
    sfVector2f pos = get_tower_placement_move(click);

    while (cur != NULL) {
        if (pos.x == cur->pos.x && pos.y == cur->pos.y &&
            cur->state != B_CLICKED)
            cur->state = B_HOVER;
        else if (cur->state != B_CLICKED)
            cur->state = B_IDLE;
        hover_tower_button(click, as->scenes[LVL].sh[1], cur);
        cur = cur->next;
    }
}

void click_lvl(sfMouseButtonEvent click, window *win, shop *sh, assets *as)
{
    for (int i = 0; i < sh->nb_but; i++)
        is_clicked(click, &sh->but[i]);
    if (win->state)
        place_tower(win->state, click, as);
    if (sh->but[0].state == B_CLICKED) {
        win->state = win->state != T_CIRCLE ? T_CIRCLE : win->state;
        sh->but[0].state = B_IDLE;
    }
    if (sh->but[1].state == B_CLICKED) {
        win->state = win->state != T_TRIANGLE ? T_TRIANGLE : win->state;
        sh->but[1].state = B_IDLE;
    }
    if (sh->but[2].state == B_CLICKED) {
        win->state = win->state != T_SQUARE ? T_SQUARE : win->state;
        sh->but[2].state = B_IDLE;
    }
    if (sh->but[3].state == B_CLICKED) {
        win->state = win->state != T_OCTAGON ? T_OCTAGON : win->state;
        sh->but[3].state = B_IDLE;
    }
}

void check_lvl(shop *sh)
{
    sfColor c = sh->but[0].color;

    c.a = 234;
    for (int i = 0; i < 4;i++) {
        if (sh->but[i].state == B_CLICKED)
            sfRectangleShape_setFillColor(sh->but[i].rect, c);
        else
            sfRectangleShape_setFillColor(sh->but[i].rect, sh->but[i].color);
    }
}