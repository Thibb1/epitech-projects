/*
** EPITECH PROJECT, 2021
** check_solution.c
** File description:
** check if valid solution or simple solution
*/

#include "solver.h"

bool check_solution(map_s *map)
{
    bool no_solution = false;

    if (map->map[0][0] == 1 || map->map[map->height - 1][map->len - 1] == 1)
        no_solution = true;
    if (no_solution) {
        my_printf("no solution found");
        free_map(map);
    }
    return (no_solution);
}