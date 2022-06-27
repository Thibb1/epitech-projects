/*
** EPITECH PROJECT, 2020
** power
** File description:
** power it
*/

int my_compute_power_it(int nb, int p)
{
    if (p < 0)
        return (0);
    else if (p == 0)
        return (1);
    return (nb * my_compute_power_it(nb, p - 1));
}
