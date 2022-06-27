/*
** EPITECH PROJECT, 2020
** my_compute_fact
** File description:
** compute fac
*/

int my_compute_factorial_rec(int nb)
{
    if (nb < 0 || 12 < nb)
        return (0);
    else if (nb == 0)
        return (1);
    else
        return (my_compute_factorial_rec(nb - 1) * nb);
}
