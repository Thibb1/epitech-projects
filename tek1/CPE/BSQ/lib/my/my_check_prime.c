/*
** EPITECH PROJECT, 2020
** my_check_prime.c
** File description:
** finds nearest prime number
*/

#include "../../include/my.h"

int my_check_prime(int nb, int i)
{
    for (; i <= (nb / 3); i += 2)
        if (nb % i == 0)
            return (my_find_prime_sup(nb + 2));
    return (nb);
}
