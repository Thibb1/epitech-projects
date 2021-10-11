/*
** EPITECH PROJECT, 2021
** path_loop.c
** File description:
** find best path
*/

#include "solver.h"

void loop_path(solver *as, path_s *path, int *found)
{
    int index = find_cheapest(as->node, path);

    if (index == as->last_node)
        *found = fill_path(as->node, path, &index);
    for (int n = 0; n < path->o_len; n++)
        if (open_path(path, index, n))
            break;
    path->c = (int *)realloc(path->c, ++path->c_len * sizeof(int));
    path->c[path->c_len - 1] = index;
    for (int n = 0; n < as->node[index].n_len; n++)
        loop_node_costs(as, path, index, n);
}

bool open_path(path_s *path, int index, int n)
{
    bool a = path->o[n] == index;

    if (a && (path->o_len - 1) != n)
        for (int x = n; x < (path->o_len - 1); x++)
            path->o[x] = path->o[x + 1];
    if (a)
        path->o = (int *)realloc(path->o, --path->o_len * sizeof(int));
    return (a);
}

int fill_path(node_s *node, path_s *path, int *index)
{
    path->p = (int *)realloc(path->p, ++path->p_len * sizeof(int));
    path->p[path->p_len - 1] = *index;
    while (node[*index].from >= 0) {
        *index = node[*index].from;
        path->p = (int *)realloc(path->p, ++path->p_len * sizeof(int));
        path->p[path->p_len - 1] = *index;
    }
    return (1);
}

int find_cheapest(node_s *node, path_s *path)
{
    int index = 0;
    double cheapest = DBL_MAX;

    for (int n = 0; n < path->o_len; n++)
        if (node[path->o[n]].cost < cheapest) {
            index = path->o[n];
            cheapest = node[path->o[n]].cost;
        }
    return (index);
}