/*
** EPITECH PROJECT, 2021
** generator_perfect.c
** File description:
** generates perfect maze
*/

void add_cluster(int x, int y, char **map)
{
    if (x >= 3 && y >= 3 && y >= x) {
        map[0][x - 2] = 'X';
        map[1][x - 1] = 'X';
    } else if (x >= 3 && y >= 3) {
        map[y - 2][0] = 'X';
        map[y - 1][1] = 'X';
    }
}