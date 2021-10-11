/*
** EPITECH PROJECT, 2020
** place_tower.c
** File description:
** check if tower can be placed and place it
*/

#include "defender.h"

sfVector2f get_tower_placement(sfMouseButtonEvent c)
{
    sfVector2f pos = {c.x, c.y};

    pos.x = ((int) (pos.x / 60)) * 60;
    pos.y = ((int) (pos.y / 60)) * 60;
    return (pos);
}

sfVector2f get_tower_placement_move(sfMouseMoveEvent c)
{
    sfVector2f pos = {c.x, c.y};

    pos.x = ((int) (pos.x / 60)) * 60;
    pos.y = ((int) (pos.y / 60)) * 60;
    return (pos);
}

int can_place_tower(int type, sfVector2f pos, assets *as)
{
    tower *current = as->t_head;

    while (current != NULL) {
        if (current->pos.x == pos.x && current->pos.y == pos.y)
            return (0);
        current = current->next;
    }
    if (pos.x >= 1255 || as->coins - (int)((log(type) + 1) * 100) < 0)
        return (0);
    if ((pos.x >= 0 && pos.x < 360 && pos.y == 60) ||
        (pos.y >= 120 && pos.y < 660 && pos.x == 300) ||
        (pos.x >= 120 && pos.x < 360 && pos.y == 660) ||
        (pos.y >= 720 && pos.y < 1020 && pos.x == 120) ||
        (pos.x >= 180 && pos.x < 1200 && pos.y == 960) ||
        (pos.y >= 660 && pos.y < 960 && pos.x == 1140) ||
        (pos.x >= 780 && pos.x < 1140 && pos.y == 660) ||
        (pos.y >= 300 && pos.y < 660 && pos.x == 780) ||
        (pos.x >= 840 && pos.x < 1260 && pos.y == 300))
        return (0);
    return (1);
}

void place_tower(int type, sfMouseButtonEvent c, assets *as)
{
    sfVector2f tower_case = get_tower_placement(c);
    char sc[1048] = "";
    float f[3] = {tower_case.x + 5, tower_case.y - 50, 0.8};
    int set[3] = {1, 45, 1};

    if (can_place_tower(type, tower_case, as)) {
        nb_to_str(sc, -((int)((log(type) + 1) * 100)));
        create_popup(as, sc, f, set);
        as->coins -= (int)((log(type) + 1) * 100);
        as->gs.t_towers += 1;
        create_tower(as, type, sfGreen, tower_case);
    }
}