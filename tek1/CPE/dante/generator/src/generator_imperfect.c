/*
** EPITECH PROJECT, 2021
** generator_imperfect.c
** File description:
** generates imperfect maze
*/

#include "generator.h"

int generator_imperfect(int x, int y)
{
    char **map = init_map(x, y);
    int pair_x = x % 2 ? 0 : 1;
    int pair_y = y % 2 ? 0 : 1;

    if (map == NULL)
        return (FAILURE);
    for (int i = 0; i < y + pair_y; i += 2)
        for (int j = 0; j < x + pair_x; j += 2)
            carve_wall(map, i, j, (int[2]){y, x});
    show_free_map1(x, y, map);
    return (0);
}


void show_free_map1(int x, int y, char **map)
{
    if (map[y - 2][x - 1] == '*' && map[y - 1][x - 2] == '*')
        map[y - 2][x - 1] = 'X';
    add_cluster(x, y, map);
    for (int i = 0; i < y; i++) {
        my_printf(i != y - 1 ? "%s\n" : "%s", map[i]);
        free(map[i]);
    }
    free(map);
}