/*
** EPITECH PROJECT, 2020
** bsqutils.c
** File description:
** utils func for bsq
*/

#include "../include/my.h"
#include "../include/bsq.h"

void init_st(st *st, int ac, char *av[])
{
    if (ac != 2 || !my_strcmp("-h", av[1])) {
        write(2, "Usage: ./bsq FILEPATH\n", 22);
        exit (84);
    } else if (stat(av[1], st)) {
        write(2, "Can't read stats\n", 18);
        exit (84);
    }
}

void init_bs(bs *bs, st st, char *path)
{
    bs->file = my_fopen(path, 'r');
    if (bs->file == -1) {
        write(2, "Can't open the file\n", 20);
        exit (84);
    }
    my_fscanf(bs->file, "%d", &bs->row_nb);
    m_check(bs->map = malloc(sizeof(int *) * bs->row_nb));
    m_check(bs->raw_map = malloc(sizeof(char) * st.st_size + 1));
    if (read(bs->file, bs->raw_map, st.st_size) < 1) {
        write(2, "Error with read\n", 16);
        exit (84);
    }
    for (int i = 0; my_grep("o.", bs->raw_map[i]); i++)
        bs->col_nb++;
    if (!bs->col_nb) {
        write(2, "Error with map\n", 15);
        exit (84);
    }
    for (int i = 0; i < bs->row_nb; i++)
        m_check(bs->map[i] = malloc(sizeof(int) * bs->col_nb));
}

void m_check(void *m_ret)
{
    if (!m_ret) {
        write(2, "Error with malloc\n", 18);
        exit (84);
    }
}

void bs_set(bs *bs, sq sq, int nb)
{
    bs->bsq[0] = nb;
    bs->bsq[1] = sq.x;
    bs->bsq[2] = sq.y;
}
