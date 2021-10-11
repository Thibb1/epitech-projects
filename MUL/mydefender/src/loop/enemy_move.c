/*
** EPITECH PROJECT, 2020
** enemy_move.c
** File description:
** basic loop move enemies
*/

#include "defender.h"

void set_phase(enemy *current)
{
    if (current->phase == 1 && current->pos.x >= 320)
        current->phase = 2;
    if (current->phase == 2 && current->pos.y >= 675)
        current->phase = 3;
    if (current->phase == 3 && current->pos.x <= 140)
        current->phase = 4;
    if (current->phase == 4 && current->pos.y >= 980)
        current->phase = 5;
    if (current->phase == 5 && current->pos.x >= 1155)
        current->phase = 6;
    if (current->phase == 6 && current->pos.y <= 685)
        current->phase = 7;
    if (current->phase == 7 && current->pos.x <= 800)
        current->phase = 8;
    if (current->phase == 8 && current->pos.y <= 320)
        current->phase = 9;
}

void set_move(enemy *current, float deltatime)
{
    if (current->phase == 1)
        current->pos.x += 10 * deltatime * current->type;
    if (current->phase == 2)
        current->pos.y += 10 * deltatime * current->type;
    if (current->phase == 3)
        current->pos.x -= 10 * deltatime * current->type;
    if (current->phase == 4)
        current->pos.y += 10 * deltatime * current->type;
    if (current->phase == 5)
        current->pos.x += 10 * deltatime * current->type;
    if (current->phase == 6)
        current->pos.y -= 10 * deltatime * current->type;
    if (current->phase == 7)
        current->pos.x -= 10 * deltatime * current->type;
    if (current->phase == 8)
        current->pos.y -= 10 * deltatime * current->type;
    if (current->phase == 9)
        current->pos.x += 10 * deltatime * current->type;
}

void check_enemy_next(assets *as, enemy *cur, enemy *next)
{
    if (next->life <= 0)  {
        sfCircleShape_destroy(next->shape);
        sfRectangleShape_destroy(next->lifebar);
        cur->next = next->next;
        enemy_coins(as, next);
        free(next);
    }
    if (next->pos.x >= 1180) {
        sfCircleShape_destroy(next->shape);
        sfRectangleShape_destroy(next->lifebar);
        cur->next = next->next;
        as->lives -= 1;
        enemy_to_base(as);
        free(next);
    }
}

void check_head(assets *as)
{
    enemy *next = as->head->next;

    if (as->head->life <= 0) {
        sfCircleShape_destroy(as->head->shape);
        sfRectangleShape_destroy(as->head->lifebar);
        as->gs.t_coins += as->head->type * 2;
        as->gs.t_enemies += 1;
        enemy_coins(as, as->head);
        free(as->head);
        as->head = next;
    }
    if (as->head->pos.x >= 1180) {
        sfCircleShape_destroy(as->head->shape);
        sfRectangleShape_destroy(as->head->lifebar);
        as->lives  -= 1;
        free(as->head);
        as->head = next;
        enemy_to_base(as);
    }
}

void enemy_move(assets *as, float deltatime)
{
    enemy *current = as->head;
    sfVector2f l_pos;

    while (current != NULL) {
        set_phase(current);
        set_move(current, deltatime);
        sfCircleShape_setPosition(current->shape, current->pos);
        l_pos = current->pos;
        l_pos.x = l_pos.x - ABS(current->life / 50) + 10;
        l_pos.y += 25;
        sfRectangleShape_setPosition(current->lifebar, l_pos);
        sfRectangleShape_setSize(current->lifebar,
            (sfVector2f) {(current->life) > 0 ? current->life / 25 : 0, 5});
        if (current->next != NULL)
            check_enemy_next(as, current, current->next);
        current = current->next;
    }
}