/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** swaps values
*/

void my_swap(int *a, int *b)
{
    int a_val;

    a_val = *a;
    *a = *b;
    *b = a_val;
}
