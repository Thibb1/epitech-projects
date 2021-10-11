/*
** EPITECH PROJECT, 2020
** arr.c
** File description:
** sh funct
*/

#include "my_sh.h"

int arr_len(char **arr)
{
    int len = 0;

    for (; arr[len]; len++);
    return (len);
}

char **copy_arr(char **arr)
{
    int len = arr_len(arr);
    char **new_arr = NULL;

    for (; arr[len]; len++);
    new_arr = malloc(sizeof(char *) * (len + 100));
    for (int i = 0; i < len; i++) {
        new_arr[i] = malloc(sizeof(char) * (my_strlen(arr[i]) + 1));
        my_strcat(new_arr[i], arr[i]);
    }
    return (new_arr);
}

void free_arr(char **arr)
{
    for (int len = 0; arr[len]; len++)
        free(arr[len]);
    free(arr);
}

void print_arr(char **arr)
{
    for (int len = 0; arr[len]; len++)
        my_printf("%s\n", arr[len]);
}