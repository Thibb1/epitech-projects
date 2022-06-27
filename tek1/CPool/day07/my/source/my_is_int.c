/*
** EPITECH PROJECT, 2020
** is_int
** File description:
** checkif long is int
*/

int my_is_int(long long n, int fn, int nb)
{
    if (!nb || (n > 21474836470 && !(fn) || ((fn) && (n > 21474836480)))) {
        return (0);
    } else if (fn)
        return (-n / 10);
    return (n / 10);
}
