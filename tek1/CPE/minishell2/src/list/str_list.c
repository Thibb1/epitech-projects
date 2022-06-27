/*
** EPITECH PROJECT, 2021
** env.c
** File description:
** env load / set / change
*/

#include "my_shell.h"

void str_list_head(str_list **head, char *str)
{
    str_list *node = NULL;

    node = (str_list *) malloc(sizeof(str_list));
    node->str = malloc(sizeof(char) * (my_strlen(str) + 1));
    node->str[0] = 0;
    my_strcat(node->str, str);
    node->next = *head;
    *head = node;
}

void str_list_push(str_list **head, char *str)
{
    str_list *node = *head;

    if (node == NULL) {
        str_list_head(head, str);
        return;
    }
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = (str_list *) malloc(sizeof(str_list));
    node->next->str = malloc(sizeof(char) * (my_strlen(str) + 1));
    node->next->str[0] = 0;
    my_strcat(node->next->str, str);
    node->next->next = NULL;
}

void str_list_free(str_list **head)
{
    str_list *node = *head;
    str_list *next = NULL;

    while (node != NULL) {
        next = node->next;
        free(node->str);
        free(node);
        node = next;
    }
}

void str_list_pop(str_list **head)
{
    str_list *node = *head;

    if (*head == NULL)
        return;
    node = (*head)->next;
    free((*head)->str);
    free(*head);
    *head = node;
}

void str_list_remove(str_list **head, int n)
{
    str_list *node = *head;
    str_list *temp = NULL;

    if (n == 0) {
        str_list_pop(head);
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (node->next == NULL)
            return;
        node = node->next;
    }
    temp = node->next;
    node->next = temp->next;
    free(temp->str);
    free(temp);
}