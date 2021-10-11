/*
** EPITECH PROJECT, 2020
** print_sticks.c
** File description:
** print hte sticks to the user
*/

#include "match.h"

void print_line(int w)
{
    for (int i = 0; i < w; i++)
        my_printf("*");
    my_printf("\n");
}

void print_sticks(settings *a, int *sticks)
{
    print_line(a->width);
    for (int i = 0; i < a->li; i++) {
        my_printf("*");
        for (int b = 1; b < a->li - i; b++)
            my_printf(" ");
        for (int b = 0; b < sticks[i]; b++)
            my_printf("|");
        for (int b = 1; b < (i + 1) + i % (i + 1) - sticks[i] + a->li - i; b++)
            my_printf(" ");
        my_printf("*\n");
    }
    print_line(a->width);
}