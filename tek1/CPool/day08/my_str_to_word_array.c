/*
** EPITECH PROJECT, 2020
** str_to_word_arr
** File description:
** convert str to word arr
*/

#include "include/my.h"

#include <stddef.h>

int my_is_alpha_num(char c)
{
    if (!(my_is_alpha_one(c)) || (c >= '0' && c <= '9'))
        return (1);
    return (0);
}

int my_strnlen(char const *str)
{
    int i = 0;
    for (; my_is_alpha_num(str[i]); i++);
    return (i);
}

int str_count_words(char const *str)
{
    int i = 0;
    int a = 0;
    int startword = 1;

    for (; str[i]; i++) {
        if (startword && my_is_alpha_num(str[i])) {
            a += my_is_alpha_num(str[i]);
            startword = 0;
        } else if (!(my_is_alpha_num(str[i])))
            startword = 1;
    }
    return (a);
}

void my_fill_ret(char **arr, int s_col, char const *str)
{
    int i = 0;
    int i_str = 0;
    int y = 0;
    for (int a = 0; i < s_col - 1; i++) {
        while (!my_is_alpha_num(str[i_str]))
            i_str++;
        y = my_strnlen(&str[i_str]);
        arr[i] = malloc(sizeof(char) * y);
        for (a = 0; a < y; a++, i_str++)
            arr[i][a] = str[i_str];
    }
}

char **my_str_to_word_array(char const *str)
{
    char **ret;
    int s_col = str_count_words(str) + 1;
    ret = malloc(sizeof(char *) * s_col);
    my_fill_ret(ret, s_col, str);
    return (ret);
}
