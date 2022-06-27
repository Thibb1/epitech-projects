/*
** EPITECH PROJECT, 2020
** my_rpg.c
** File description:
** controller function / starting point
*/

#include "my_rpg.h"

void start_rpg(void)
{
    my_rpg rpg;

    load_all(&rpg);
    loop(&rpg);
    unload_all(rpg);
}