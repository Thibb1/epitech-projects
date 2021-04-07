/*
** EPITECH PROJECT, 2020
** Compute square
** File description:
** do square root
*/

int my_compute_square_root(int nb)
{
    int i = 1;
    if (nb < 1)
        return (0);
    while (i * i <= nb)
        i++;
    i--;
    if (i * i == nb)
        return (i);
    return (0);
}
