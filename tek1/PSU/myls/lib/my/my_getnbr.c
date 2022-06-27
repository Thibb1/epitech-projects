/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** returns nb in str
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    long long n = 0;
    int i = 0;
    int nb = 0;
    int fn = 0;

    while ((str[i]) && (nb < 11) && (!(nb) || (47 < str[i] && str[i] < 58))) {
        if (str[i] == '-') {
            fn = (fn % 2 + 1) % 2;
        } else if (47 < str[i] && str[i] < 58) {
            n = 10 * (n + str[i] - '0');
            nb++;
        }
        i++;
    }
    return (my_is_int(n, fn, nb));
}
