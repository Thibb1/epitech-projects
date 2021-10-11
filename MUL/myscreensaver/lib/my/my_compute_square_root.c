/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c
** File description:
** returns square root of nb
*/

int my_compute_square_root(int nb)
{
    int i = 1;

    if (nb < 1)
        return (0);
    for (; i * i <= nb; i++);
    i--;
    if (i * i == nb)
        return (i);
    return (0);
}
