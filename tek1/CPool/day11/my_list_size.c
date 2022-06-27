/*
** EPITECH PROJECT, 2020
** my_list_size
** File description:
** list size calculator
*/

#include <stdlib.h>
#include <unistd.h>
#include "include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int size = 0;
    struct linked_list *tmp = begin;

    for (;tmp != NULL; tmp = tmp->next, size++);
    return (size);
}
