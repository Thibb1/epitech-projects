/*
** EPITECH PROJECT, 2020
** my_params_to_list
** File description:
** turn params into list with rev order
*/

#include <stdlib.h>
#include <unistd.h>
#include "mylist.h"
#include "my.h"

void my_put_av_list(struct linked_list **list, char const *data)
{
    struct linked_list *h_point = *list;
    struct linked_list *n_point = NULL;

    if (h_point == NULL) {
        h_point = malloc(sizeof(struct linked_list));
        h_point->data = malloc(sizeof(char) * my_strlen(data));
        my_strcat(h_point->data, data);
        h_point->next = NULL;
        *list = h_point;
    } else {
        while (h_point->next != NULL)
            h_point = h_point->next;
        h_point->next = malloc(sizeof(struct linked_list));
        h_point->next->data = malloc(sizeof(char) * my_strlen(data));
        my_strcat(h_point->next->data, data);
        h_point->next->next = NULL;
    }
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    struct linked_list *list = NULL;

    for (int i = 0; i < ac; i++)
        my_put_av_list(&list, av[i]);
    return (list);
}
