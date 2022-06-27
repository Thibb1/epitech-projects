/*
** EPITECH PROJECT, 2020
** save_and_close.c
** File description:
** basic routine to stop and save the app
*/

#include "defender.h"

void unload_game(window *win, assets *as)
{
    for (int i = 0; i < NB_SCENE; i++) {
        if (as->scenes[i].nb_but)
            free(as->scenes[i].but);
        if (as->scenes[i].nb_text)
            free(as->scenes[i].text);
    }
    sfFont_destroy(as->font);
    free(as->scenes);
    sfRenderWindow_destroy(win->rw);
}

void remove_pops(assets *as)
{
    popup *cur = as->pop;
    popup *next = NULL;

    while (cur != NULL) {
        sfText_destroy(cur->text);
        sfClock_destroy(cur->clock);
        next = cur->next;
        free(cur);
        cur = next;
    }
}

void remove_lists(assets *as)
{
    enemy *current = as->head;
    enemy *next = NULL;
    tower *tow = as->t_head;
    tower *tow_n = NULL;

    while (current != NULL) {
        sfCircleShape_destroy(current->shape);
        sfRectangleShape_destroy(current->lifebar);
        next = current->next;
        free(current);
        current = next;
    }
    while (tow != NULL) {
        sfCircleShape_destroy(tow->radius);
        sfCircleShape_destroy(tow->shape);
        sfCircleShape_destroy(tow->outshape);
        tow_n = tow->next;
        free(tow);
        tow = tow_n;
    }
}
