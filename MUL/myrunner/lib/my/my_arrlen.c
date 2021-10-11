/*
** EPITECH PROJECT, 2020
** arr_len
** File description:
** calculate size arr
*/

#include <stddef.h>

int my_arrlen(char * const *tab)
{
    int i = 0;
    for (; tab[i] != NULL; i++);
    return (i);
}
