/*
** EPITECH PROJECT, 2021
** str_to_arr.c
** File description:
** get words and parse them in a 2D array or free them
*/

#include "my.h"

int arr_len(char **arr)
{
    int len = 0;

    for (; arr[len] != NULL; len++);
    return (len);
}

void arr_free(char **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i];)
        free(arr[i++]);
    free(arr);
}

int str_count_words(const char *str, const char *separator)
{
    int x = 0;
    int t = 0;

    for (int i = 0; str[i] != 0;) {
        for (; str[i] && my_grep(separator, str[i]); i++);
        for (t = 0; str[i] && !my_grep(separator, str[i]); i++, t++);
        x += t ? 1 : 0;
    }
    return (x);
}

char **str_to_arr(const char *str, const char *separator)
{
    int b = 0;
    int x = 0;
    int nb = str_count_words(str, separator);
    char **av = malloc(sizeof(char *) * (nb + 1));

    for (int i = 0; str[i];) {
        for (; str[i] && my_grep(separator, str[i]); i++);
        for (b = 0; str[i] && !my_grep(separator, str[i]); i++, b++);
        if (b) {
            av[x] = malloc(sizeof(char) * (b + 1));
            av[x][0] = 0;
            my_strncat(av[x], &str[i - b], b);
            x++;
        }
    }
    av[x] = 0;
    return (av);
}