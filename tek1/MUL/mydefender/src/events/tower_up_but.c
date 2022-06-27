/*
** EPITECH PROJECT, 2020
** place_tower.c
** File description:
** check if tower can be placed and place it
*/

#include "defender.h"

void check_click_tower(sfMouseButtonEvent click, shop sh)
{
    is_clicked(click, &sh.but[0]);
    is_clicked(click, &sh.but[1]);
}

int check_tower_button(shop sh, tower *c, assets *as)
{
    char sc[1048] = "";
    int n = 0;
    float f[3] = {1250, 660, 1.2};
    int set[3] = {LVL, 50, 1};
    int price = (((c->level - 1) * 50 + (int)(100 * (log(c->type) + 1))) / 2);

    if (sh.but[0].state == B_CLICKED && as->coins - (c->level * 50) >= 0) {
        as->coins -= c->level * 50;
        nb_to_str(sc, -(c->level * 50));
        c->level += 1;
        c->range += 10;
    } else if (sh.but[1].state == B_CLICKED) {
        nb_to_str(sc, price);
        as->coins += price;
        n = 1;
    }
    create_popup(as, sc, f, set);
    sh.but[0].state = B_IDLE;
    sh.but[1].state = B_IDLE;
    return (n);
}

void hover_tower_button(sfMouseMoveEvent click, shop sh, tower *c)
{
    if (c->level >= 6)
        sh.but[0].state = B_DISABLE;
    else if (sh.but[0].state == B_DISABLE)
        sh.but[0].state = B_HOVER;
    is_hover(click, &sh.but[0]);
    is_hover(click, &sh.but[1]);
}

void pop_tower(assets *as, tower *cur)
{
    if (cur == NULL)
        return;
    as->t_head = cur->next;
    sfCircleShape_destroy(cur->radius);
    sfCircleShape_destroy(cur->shape);
    sfCircleShape_destroy(cur->outshape);
    free(cur);
}

void remove_tower(assets *as, int n)
{
    tower *cur = as->t_head;
    tower *temp = NULL;

    if (n == 0) {
        pop_tower(as, cur);
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (cur->next == NULL)
            return;
        cur = cur->next;
    }
    temp = cur->next;
    cur->next = temp->next;
    sfCircleShape_destroy(temp->radius);
    sfCircleShape_destroy(temp->shape);
    sfCircleShape_destroy(temp->outshape);
    free(temp);
}
