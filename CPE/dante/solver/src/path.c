/*
** EPITECH PROJECT, 2021
** path.c
** File description:
** find shortest path
*/

#include "solver.h"

int find_path(map_s *m)
{
    solver *as = NULL;
    path_s *path = NULL;
    int found = 0;

    if (m_check(as = create_solver(m)))
        return (FAILURE);
    if (m_check(path = create_path()))
        return (FAILURE);
    as->node[0].cost_g = 0;
    as->node[0].cost = as->node[0].cost_d;
    while (!found && path->o_len) {
        loop_path(as, path, &found);
    }
    print_path(m, path, found);
    free_path(m, as, path);
    return (SUCCESS);
}

void print_path(map_s *m, path_s *path, int solution)
{
    if (solution == 0) {
        my_printf("no solution found\n");
        return;
    }
    for (int y = 0; y < m->height; y++) {
        for (int x = 0; x < m->len; x++) {
            if (m->map[y][x] == 1)
                my_printf("X");
            else {
                print_case(m->pmap[y][x], path);
            }
        }
        my_printf(y != m->height - 1 ? "\n" : "");
    }
}

path_s *create_path(void)
{
    path_s *path = NULL;

    if (m_check(path = malloc(sizeof(path_s))))
        return (NULL);
    path->p_len = 0;
    path->p = NULL;
    path->o_len = 1;
    if (m_check(path->o = (int *)malloc(sizeof(int))))
        return (NULL);
    path->o[0] = 0;
    path->c_len = 0;
    path->c = NULL;
    return (path);
}

void free_path(map_s *m, solver *as, path_s *path)
{
    free(path->p);
    free(path->o);
    free(path->c);
    free(path);
    for (int x = 0; x < as->nb_node; x++)
        free(as->node[x].n);
    free(as->node);
    free(as->route);
    free(as);
    free_map(m);
}

void print_case(int pmap, path_s *path)
{
    int is_path = 0;

    for (int n = 0; n < path->p_len; n++)
        if (pmap == path->p[n])
            is_path++;
    my_printf(is_path ? "o" : "*");
}