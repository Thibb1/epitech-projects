/*
** EPITECH PROJECT, 2021
** maths.c
** File description:
** basic maths functions
*/

#include "my.h"

double my_sqrt(double nb)
{
    double low = 0;
    double result = nb;
    double high = nb;
    double p_result = -1;

    if (nb < 0)
        return (-1);
    while (ABS(p_result - result) >= 0.00001) {
        p_result = result;
        result = (low + high) / 2;
        if (result * result > nb)
            high = result;
        else
            low = result;
    }
    return (result);
}

double my_pow(double x, int y)
{
    const double mult = x;

    if (y <= 0)
        return (1);
    for (--y; y--;)
        x *= mult;
    return (x);
}