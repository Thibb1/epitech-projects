/*
** EPITECH PROJECT, 2021
** solver.c
** File description:
** A* solver create
*/

#include "solver.h"

solver *create_solver(map_s *m)
{
    solver *as = NULL;

    if (m_check(as = malloc(sizeof(solver))))
        return (NULL);
    as->nb_node = 0;
    if (m_check(as->node = create_nodes(as, m)))
        return (NULL);
    distance_node_cost(as);
    as->nb_route = 0;
    as->route = NULL;
    for (int y = 0; y < m->height; y++)
        for (int x = 0; x < m->len; x++)
            if (m->pmap[y][x] >= 0)
                nested_route(as, m, x, y);
    return (as);
}

node_s *create_nodes(solver *as, map_s *m)
{
    node_s *node = NULL;
    int index;

    for (int y = 0; y < m->height; y++)
        for (int x = 0; x < m->len; x++) {
            if (m->map[y][x] == 0) {
                node = (node_s *)realloc(node, sizeof(node_s) * ++as->nb_node);
                index = as->nb_node - 1;
                node[index].x = x;
                node[index].y = y;
                node[index].n = NULL;
                node[index].n_len = 0;
                node[index].cost_g = DBL_MAX;
                node[index].from = -1;
                m->pmap[y][x] = index;
            }
        }
    return (node);
}

void distance_node_cost(solver *as)
{
    int d_last = as->nb_node - 1;
    node_s *node = as->node;

    as->last_node = d_last;
    for (int x = 0; x < as->nb_node; x++) {
        as->node[x].cost_d = my_pow(node[d_last].y - node[x].y, 2);
        as->node[x].cost_d += my_pow(node[d_last].x - node[x].x, 2);
        as->node[x].cost_d = my_sqrt(node[x].cost_d);
    }
}

void nested_route(solver *as, map_s *m, int x, int y)
{
    int y_shift = 0;
    int x_shift = 0;
    int x_list[2] = {x, 0};
    int y_list[2] = {y, 0};

    for (int ya = y - 1, y_shift = 0; ya <= y + 1; ya++, y_shift++) {
        if (ya < 0 || ya >= m->height)
            continue;
        for (int xa = x - 1, x_shift = 0; xa <= x + 1; xa++, x_shift++) {
            if (y_shift == x_shift || y_shift == x_shift - 2 ||
                x_shift == y_shift - 2)
                continue;
            if (xa < 0 || xa >= m->len || ((xa == x) && (ya == y)))
                continue;
            x_list[1] = xa;
            y_list[1] = ya;
            if (m->pmap[ya][xa] >= 0)
                create_route(as, m, x_list, y_list);
        }
    }
}

void create_route(solver *as, map_s *m, int x_list[2], int y_list[2])
{
    int n = as->nb_route++;
    int x = m->pmap[y_list[0]][x_list[0]];
    int y = m->pmap[y_list[1]][x_list[1]];

    as->route = (rout_s *)realloc(as->route, sizeof(rout_s) * as->nb_route);
    as->route[n].cost = my_pow(as->node[y].y - as->node[x].y, 2);
    as->route[n].cost += my_pow(as->node[y].x - as->node[x].x, 2);
    as->route[n].cost = my_sqrt(as->route[n].cost);
    as->route[n].x = x;
    as->route[n].y = y;
    as->node[x].n = (int *)realloc(as->node[x].n,
        ++as->node[x].n_len * sizeof(int));
    as->node[x].n[as->node[x].n_len - 1] = n;
}