/*
** EPITECH PROJECT, 2021
** node_cost_loop.c
** File description:
** find all current nodes costs
*/

#include  "solver.h"

void loop_node_costs(solver *as, path_s *path, int index, int n)
{
    double cost;
    bool should_open = true;
    rout_s *route = as->route;
    node_s *node = as->node;
    int n_index = node[index].n[n];

    if (check_closed(as, path, n_index))
        return;
    cost = node[index].cost_g + route[n_index].cost;
    if (path->o_len > 0)
        should_open = check_open(as, path, n_index);
    if (should_open || (cost < node[route[n_index].y].cost_g)) {
        search_costs(as, index, n_index, cost);
        if (should_open) {
            path->o = (int *)realloc(path->o, ++path->o_len * sizeof(int));
            path->o[path->o_len - 1] = route[n_index].y;
        }
    }
}

void search_costs(solver *as, int index, int n_index, double cost)
{
    double cost_d = as->node[as->route[n_index].y].cost_d;

    as->node[as->route[n_index].y].from = index;
    as->node[as->route[n_index].y].cost_g = cost;
    as->node[as->route[n_index].y].cost = cost + cost_d;
}

bool check_closed(solver *as, path_s *path, int n_index)
{
    for (int x = 0; x < path->c_len; x++)
        if (as->route[n_index].y == path->c[x])
            return (true);
    return (false);
}

bool check_open(solver *as, path_s *path, int n_index)
{
    for (int x = 0; x < path->o_len; x++)
        if (as->route[n_index].y == path->o[x])
            return (false);
    return (true);
}