/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** calls main funct
*/

#include "solver.h"

int main(int ac, char **av)
{
    char *buffer = NULL;
    map_s map = {0, 1, NULL, NULL};

    if (ac != 2)
        return (FAILURE);
    if (m_check(buffer = get_map(av[1])))
        return (FAILURE);
    if (parse_map(&map, buffer))
        return (FAILURE);
    free(buffer);
    if (check_solution(&map))
        return (SUCCESS);
    return (find_path(&map));
}