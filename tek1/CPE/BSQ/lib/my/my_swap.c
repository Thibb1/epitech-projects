/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** swaps *a and *b
*/

void my_swap(int *a, int *b)
{
    int a_val = *a;
    *a = *b;
    *b = a_val;
}
