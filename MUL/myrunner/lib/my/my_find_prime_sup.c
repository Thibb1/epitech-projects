/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** returns prime sup of nb
*/

#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    int i;

    if (nb <= 2)
        return (2);
    else if (nb % 2) {
        i = 3;
        return (my_check_prime(nb, i));
    }
    return (my_find_prime_sup(nb + 1));
}
