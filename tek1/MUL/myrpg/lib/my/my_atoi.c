/*
** EPITECH PROJECT, 2021
** my_atoi.c
** File description:
** get integer number from str
*/

#include "my.h"

int my_atoi(const char *str)
{
    int number = 0;
    int sign = 1;

    if (my_grep("-+", *str))
        sign *= *str++ == '-' ? -1 : 1;
    while (*str && *str >= '0' && *str <= '9') {
        number *= 10;
        number += *str++ - '0';
    }
    return (number * sign);
}

char *my_itoa(int number)
{
    char *str = NULL;
    int ilen = my_ilen(number);
    int negative = number;
    int i = 0;

    if (m_check(str = malloc(sizeof(char) * ilen + 1)))
        return (NULL);
    *str = '\0';
    number *= number < 0 ? -1 : 1;
    do
        *(str + i++) = number % 10 + '0';
    while ((number /= 10) > 0);
    if (negative < 0)
        *(str + i++) = '-';
    *(str + i) = 0;
    return (my_revstr(str));
}

int my_ilenhelp(unsigned number)
{
    if (number >= 1000000000)
        return (10);
    if (number >= 100000000)
        return (9);
    if (number >= 10000000)
        return (8);
    if (number >= 1000000)
        return (7);
    if (number >= 100000)
        return (6);
    if (number >= 10000)
        return (5);
    if (number >= 1000)
        return (4);
    if (number >= 100)
        return (3);
    if (number >= 10)
        return (2);
    return (1);
}

int my_ilen(const int number)
{
    if (number < 0)
        return (my_ilenhelp(-number) + 1);
    return (my_ilenhelp(number));
}
