/*
** EPITECH PROJECT, 2020
** list.c
** File description:
** init chained list
*/

#include "defender.h"

void set_enemy_data(enemy *cur, int type, sfColor c)
{
    cur->phase = 1;
    cur->life = (1 / (log(type) + 1)) * 1000 ;
    cur->type = type;
    cur->pos = (sfVector2f) {-20, 80};
    cur->shape = sfCircleShape_create();
    cur->lifebar = sfRectangleShape_create();
    if (type != E_CIRCLE)
        sfCircleShape_setPointCount(cur->shape, type);
    sfCircleShape_setFillColor(cur->shape, c);
    sfCircleShape_setRadius(cur->shape, 10);
    sfRectangleShape_setFillColor(cur->lifebar, sfRed);
    sfRectangleShape_setPosition(cur->lifebar,
        (sfVector2f) {-10 - (cur->life / 50), 105});
    sfRectangleShape_setSize(cur->lifebar,
        (sfVector2f) {cur->life / 25, 5});
}

enemy *head_enemy(int type, sfColor c)
{
    enemy *head = malloc(sizeof(enemy));

    set_enemy_data(head, type, c);
    head->next = NULL;
    return (head);
}

void create_enemy(enemy *head, int type, sfColor c)
{
    enemy *current = head;

    while (current->next != NULL)
        current = current->next;
    current->next = malloc(sizeof(enemy));
    set_enemy_data(current->next, type, c);
    current->next->next = NULL;
}

void create_tower(assets *as, int type, sfColor c, sfVector2f pos)
{
    tower *current = as->t_head;

    if (current == NULL) {
        as->t_head = malloc(sizeof(tower));
        set_tower(as->t_head, c, pos, type);
        as->t_head->next = NULL;
    } else {
        while (current->next != NULL)
            current = current->next;
        current->next = malloc(sizeof(tower));
        set_tower(current->next, c, pos, type);
        current->next->next = NULL;
    }
}