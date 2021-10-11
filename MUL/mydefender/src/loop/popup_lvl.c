/*
** EPITECH PROJECT, 2020
** main_loop.c
** File description:
** basic loop that calls other loops
*/

#include "defender.h"

void enemy_coins(assets *as, enemy *cur)
{
    float f[3] = {cur->pos.x, cur->pos.y, 0.6};
    int set[3] = {1, 40, 1};
    char sc[1048] = "";

    as->coins += cur->type * 2;
    nb_to_str(sc, cur->type * 2);
    create_popup(as, sc, f, set);
}

void enemy_to_base(assets *as)
{
    float f[3] = {1155, 400, 0.7};
    int set[3] = {1, 40, 2};

    create_popup(as, "Arrgggh", f, set);
}