/*
** EPITECH PROJECT, 2021
** generator_perfect.c
** File description:
** generates perfect maze
*/

#include "generator.h"

int generator_perfect(int x, int y)
{
    char **map = init_map(x, y);
    int pair_x = x % 2 ? 0 : 1;
    int pair_y = y % 2 ? 0 : 1;

    if (map == NULL)
        return (FAILURE);
    for (int i = 0; i < y + pair_y; i += 2)
        for (int j = 0; j < x + pair_x; j += 2)
            carve_wall(map, i, j, (int[2]){y, x});
    show_free_map(x, y, map);
    return (0);
}

void carve_wall(char **map, int i, int j, int coords[2])
{
    if (j == 0 && i != 0) {
        map[i - 1][0] = '*';
    } else if (i == 0  && j != 0) {
        map[0][j - 1] = '*';
    }
    if (j != 0 && i != 0 && i != coords[0] && j != coords[1]) {
        if (RAND_INT(0, 1))
            map[i - 1][j] = '*';
        else
            map[i][j - 1] = '*';
    }
    if (i == coords[0] && j != coords[1] && RAND_INT(0, 1))
        map[i - 1][j] = '*';
    if (j == coords[1] && i != coords[0] && RAND_INT(0, 1))
        map[i][j - 1] = '*';
}

char **init_map(int x, int y)
{
    char **map = NULL;

    srand(time(NULL));
    if (y == 0 || x == 0 || m_check(map = malloc(sizeof(char *) * y)))
        return (NULL);
    for (int i = 0; i < y; i++) {
        if (m_check(map[i] = malloc(sizeof(char) * x + 1)))
            return (NULL);
        for (int j = 0; j <= x; j++)
            map[i][j] = j == x ? 0 : j % 2 || i % 2 ? 'X' : '*';
    }
    map[y - 1][x - 1] = !(x % 2) || !(y % 2) ? '*' : map[y - 1][x - 1];
    map[y - 2][x - 1] = !(y % 2) ? '*' : map[y - 2][x - 1];
    return (map);
}

void show_free_map(int x, int y, char **map)
{
    if (map[y - 2][x - 1] == '*' && map[y - 1][x - 2] == '*')
        map[y - 2][x - 1] = 'X';
    for (int i = 0; i < y; i++) {
        my_printf(i != y - 1 ? "%s\n" : "%s", map[i]);
        free(map[i]);
    }
    free(map);
}