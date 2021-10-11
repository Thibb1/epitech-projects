/*
** EPITECH PROJECT, 2020
** bsq.c
** File description:
** biggest square finder
*/

#include "../include/my.h"
#include "../include/bsq.h"

int main(int ac, char *av[])
{
    bs bs = {{0, 0, 0}, 0, 0, 0, NULL, NULL};
    st st;
    int o_size = 0;
    init_st(&st, ac, av);
    init_bs(&bs, st, av[1]);
    process_map(&bs);
    for (o_size = st.st_size - 1; bs.row_nb; bs.row_nb /= 10, o_size--);
    write(1, bs.raw_map, o_size);
    for (int i = 0; i < bs.row_nb; i++)
        free(bs.map[i]);
    free(bs.map);
    free(bs.raw_map);
    my_fclose(bs.file);
    return (0);
}

void process_map(bs *bs)
{
    int i = 0;
    int b = 0;
    for (int i = 0; i < bs->row_nb; i++) {
        for (b = 0; my_grep("o.", bs->raw_map[bs->col_nb * i + b + i]); b++);
        if (b != bs->col_nb) {
            write(2, "Error with map\n", 15);
            exit(84);
        }
    }
    for (; i < bs->row_nb; i++)
        for (b = 0; bs->raw_map[i * (bs->col_nb + 1) + b] != '\n'; b++)
            bs->map[i][b] = bs->raw_map[i* (bs->col_nb + 1) + b] == 'o' ? 0 : 1;
    for (i = bs->row_nb - 1; i >= 0; i--)
        for (b = bs->col_nb - 1; b >= 0; b--)
            bs->map[i][b] = bs->map[i][b] ? map_algo(bs, i, b) : 0;
    for (i = bs->bsq[1]; i < bs->bsq[1] + bs->bsq[0]; i++)
        for (b = bs->bsq[2]; b < bs->bsq[2] + bs->bsq[0]; b++)
            bs->raw_map[i * (bs->col_nb + 1) + b] = 'x';
}

int map_algo(bs *bs, int x, int y)
{
    sq sq = {0, 0, 0, x, y};
    if (x == bs->row_nb - 1 || y == bs->col_nb - 1) {
        sq.diag = 0;
        sq.down = 0;
        sq.right = 0;
    } else {
        sq.diag = bs->map[x + 1][y + 1];
        sq.down = bs->map[x][y + 1];
        sq.right = bs->map[x + 1][y];
    }
    return (map_check(bs, sq));
}

int map_check(bs *bs, sq sq)
{
    if (sq.diag <= sq.down && sq.diag <= sq.right) {
        sq.diag++;
        if (sq.diag >= bs->bsq[0])
            bs_set(bs, sq, sq.diag);
        return (sq.diag);
    } else if (sq.down <= sq.diag && sq.down <= sq.right) {
        sq.down++;
        if (sq.down >= bs->bsq[0])
            bs_set(bs, sq, sq.down);
        return (sq.down);
    }
    sq.right++;
    if (sq.right >= bs->bsq[0])
        bs_set(bs, sq, sq.right);
    return (sq.right);
}
