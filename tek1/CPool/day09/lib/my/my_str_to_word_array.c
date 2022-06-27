/*
** EPITECH PROJECT, 2020
** str_to_word_arr
** File description:
** convert str to word arr
*/

#include <stdlib.h>

int my_is_alpha_num(char c);

int my_strnlen(char const *str);

int str_count_words(char const *str);

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
