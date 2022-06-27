/*
** EPITECH PROJECT, 2020
** bsq.h
** File description:
** bsq file functions
*/

#ifndef BSQ
#define BSF
#include <sys/stat.h>
typedef struct stat st;
typedef struct bs_s {
    int bsq[3];
    int row_nb;
    int col_nb;
    int file;
    int **map;
    char *raw_map;
} bs;
typedef struct sq_s {
    int diag;
    int down;
    int right;
    int x;
    int y;
} sq;
void init_st(st *st, int ac, char *av[]);
void m_check(void *m_ret);
void init_bs(bs *bs, st st, char *path);
void bs_set(bs *bs, sq sq, int nb);
int map_check(bs *bs, sq sq);
int map_algo(bs *bs, int x, int y);
void process_map(bs *bs);

int my_fopen(const char *filepath, const char accesmode);
int my_fclose(int file);
int my_fscanf(int file, const char *format, ...);
#endif
