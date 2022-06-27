/*
** EPITECH PROJECT, 2020
** is_int
** File description:
** checkif long is int
*/

int my_is_int(long long n, int x, int a)
{
    if (!n || !a ||
        ((n > 21474836470 && !(x)) || ((x) && (n > 21474836480)))) {
        return (0);
    } else if (x)
        return (-n / 10);
    return (n / 10);
}
