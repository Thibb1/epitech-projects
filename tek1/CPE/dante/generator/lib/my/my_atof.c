/*
** EPITECH PROJECT, 2021
** my_atof.c
** File description:
** get float number from str
*/

#include "my.h"

double my_atof(const char *str)
{
    double number = 0.0;
    double factor = 1.0;

    if (my_grep("-+", *str))
        factor *= *str++ == '-' ? -1.0 : 1.0;
    while (*str && *str >= '0' && *str <= '9')
        number = number * 10.0 + *str++ - '0';
    if (*str++ == '.')
        while (*str && *str >= '0' && *str <= '9') {
            number = number * 10.0 + *str++ - '0';
            factor /= 10.0;
        }
    return (number * factor);
}

char *my_ftoa(double number, int precision)
{
    char *str = NULL;
    int ilen = my_ilen((int)number) + precision + 1;
    int negative = number;
    int i = 0;

    if (m_check(str = malloc(sizeof(char) * ilen + 1)))
        return (NULL);
    number = ABS(number) * my_pow(10, precision) + 0.5555555;
    do
        *(str + i++) = (int)number % 10 + '0';
    while (((number /= 10) || !number) && i < precision);
    if (precision > 0)
        *(str + i++) = '.';
    do
        *(str + i++) = (int)number % 10 + '0';
    while ((number /= 10) >= 1);
    if (negative < 0)
        *(str + i++) = '-';
    *(str + i) = 0;
    return (my_revstr(str));
}