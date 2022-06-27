/*
** EPITECH PROJECT, 2021
** reset.c
** File description:
** reset.c
*/

#include "defender.h"

void delete_list_enemy(enemy **head)
{
    enemy *current = *head;
    enemy *next;

    while (current != NULL) {
        next = current->next;
        sfCircleShape_destroy(current->shape);
        sfRectangleShape_destroy(current->lifebar);
        free(current);
        current = next;
    }
    *head = NULL;
}

void delete_list_tower(tower **head)
{
    tower *current = *head;
    tower *next;

    while (current != NULL) {
        sfCircleShape_destroy(current->radius);
        sfCircleShape_destroy(current->shape);
        sfCircleShape_destroy(current->outshape);
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void delete_list_popup(popup **head)
{
    popup *current = *head;
    popup *next;

    while (current != NULL) {
        sfClock_destroy(current->clock);
        sfText_destroy(current->text);
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

void reset_assets(assets *as)
{
    sfClock_destroy(as->timer);
    as->timer = sfClock_create();
    sfClock_destroy(as->s);
    as->s = sfClock_create();
    as->current_s = 0;
    as->coins = START_GOLD;
    as->lives = 5;
}

void reset_game(window *win, assets *as)
{
    win->launched = 0;
    reset_assets(as);
    win->scenes = as->scenes;
    delete_list_enemy(&as->head);
    delete_list_tower(&as->t_head);
    delete_list_popup(&as->pop);
    win->state = 0;
}
