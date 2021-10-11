/*
** EPITECH PROJECT, 2020
** check_tower.c
** File description:
** check if tower in range
*/

#include "defender.h"

void color_tow(window *win, shop sh, tower *tow)
{
    sfColor c = sfGreen;
    sfVector2f pos = {tow->pos.x - (tow->range / 2) + 30,
        tow->pos.y - (tow->range / 2) + 30};
    c.a = 224;

    if (tow->state == B_IDLE)
        sfCircleShape_setFillColor(tow->outshape, sfGreen);
    else {
        sfCircleShape_setPosition(tow->radius, pos);
        sfCircleShape_setFillColor(tow->outshape, c);
        sfCircleShape_setRadius(tow->radius, tow->range / 2);
        sfRenderWindow_drawCircleShape(win->rw, tow->radius, NULL);
    }
    if (tow->state == B_CLICKED) {
        sfRenderWindow_drawRectangleShape(win->rw, sh.but[0].rect, NULL);
        sfRenderWindow_drawRectangleShape(win->rw, sh.but[1].rect, NULL);
        sfRenderWindow_drawText(win->rw, sh.text[4].text, NULL);
        sfRenderWindow_drawText(win->rw, sh.text[5].text, NULL);
    }
}

void pop_life(assets *as, tower *tow, enemy *cur)
{
    float fa[3] = {tow->pos.x + 15, tow->pos.y - 35, 0.5};
    float fb[3] = {cur->pos.x, cur->pos.y - 20, 0.5};
    int set_a[3] = {1, 30, 0};
    int set_b[3] = {1, 20, 2};
    char sc[1048] = "";

    nb_to_str(sc, -((int)(log(tow->type * tow->level * 10) * 50)));
    create_popup(as, "Piou", fa, set_a);
    create_popup(as, sc, fb, set_b);
}

void check_tower(assets *as)
{
    enemy *e = as->head;
    tower *t = as->t_head;
    int x;
    int y;

    while (t != NULL) {
        while (e != NULL) {
            x = (t->pos.x + 25 - e->pos.x) * (t->pos.x + 25 - e->pos.x);
            y = (t->pos.y + 25 - e->pos.y -5) * (t->pos.y + 25 - e->pos.y);
            if ((t->range / 2) * (t->range / 2) - (x + y) >= 0) {
                e->life -= log(t->type * t->level * 10) * 50;
                pop_life(as, t, e);
                break;
            }
            e = e->next;
        }
        e = as->head;
        t = t->next;
    }
}