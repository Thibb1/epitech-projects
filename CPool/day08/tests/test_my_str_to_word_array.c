/*
** EPITECH PROJECT, 2020
** test_my_str_word_arr
** File description:
** test word arr
*/

#include <criterion/criterion.h>

#include "../include/my.h"

char **my_str_to_word_array(char const *str);

char *concat_params(int argc, char **argv);

Test(my_str_to_word_array, test_str_to_word)
{
    char *str = "=+Task04=Vraiment *simpliste 0123456789 tm t c";
    char **sta = my_str_to_word_array(str);
    cr_assert_eq(my_putstr(concat_params(7, sta)), 0);
    free(sta);
}
