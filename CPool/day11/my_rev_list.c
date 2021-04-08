/*
** EPITECH PROJECT, 2020
** my_rev_sort
** File description:
** sort linked list in rev
*/

#include <stdlib.h>
#include <unistd.h>
#include "mylist.h"

void my_rev_list(linked_list_t **begin)
{
    struct linked_list *t_begin = *begin;
    struct linked_list *t = NULL;
    struct linked_list *t_next = t_begin->next;

    for (; t_begin->next; t_begin = t_next) {
        t_next = t_begin->next;
        t_begin->next = t;
        t = t_begin;
    }
    t_begin->next = t;
    *begin = t_begin;
}
