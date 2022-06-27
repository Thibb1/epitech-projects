/*
** EPITECH PROJECT, 2020
** binary.h
** File description:
** includes for binary binary
*/

#ifndef SOLVE
#define SOLVE
#include "my.h"
typedef struct map_s {
    int len;
    int height;
    int **map;
    int **pmap;
} map_s;

typedef struct node_s {
    int x;
    int y;
    int *n;
    int n_len;
    double cost;
    double cost_g;
    double cost_d;
    int from;
} node_s;

typedef struct rout_s {
    double cost;
    int x;
    int y;
} rout_s;

typedef struct solver {
    int last_node;
    int nb_node;
    node_s *node;
    int nb_route;
    rout_s *route;
} solver;

typedef struct path_s {
    int p_len;
    int *p;
    int o_len;
    int *o;
    int c_len;
    int *c;
} path_s;

bool check_solution(map_s *map);

void loop_node_costs(solver *as, path_s *path, int index, int n);
void search_costs(solver *as, int index, int n_index, double cost);
bool check_closed(solver *as, path_s *path, int n_index);
bool check_open(solver *as, path_s *path, int n_index);

void loop_path(solver *as, path_s *path, int *found);
bool open_path(path_s *path, int index, int n);
int fill_path(node_s *node, path_s *path, int *index);
int find_cheapest(node_s *node, path_s *path);

int find_path(map_s *m);
path_s *create_path(void);
void print_case(int pmap, path_s *path);
void print_path(map_s *m, path_s *path, int solution);
void free_path(map_s *m, solver *as, path_s *path);

solver *create_solver(map_s *m);
node_s *create_nodes(solver *as, map_s *m);
void distance_node_cost(solver *as);
void nested_route(solver *as, map_s *m, int x, int y);
void create_route(solver *as, map_s *m, int x_list[2], int y_list[2]);

double my_sqrt(double nb);
double my_pow(double nb, int pow);

char *get_map(char *path);
int parse_map(map_s *m, char *buffer);
void free_map(map_s *m);
#endif