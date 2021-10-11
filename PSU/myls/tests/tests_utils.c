/*
** EPITECH PROJECT, 2020
** tests_utils.c
** File description:
** test utils
*/

#include "../include/mytest.h"

Test(my_strcpy, copy_string_into_dest)
{
    char dest[6] = {0};

    my_strcpy(dest, "Hello");
    cr_assert_str_eq("Hello", dest);
}

Test(str_count_words, str_count_words_test)
{
    char *src = "Hello world!";
    int a = str_count_words(src);
    cr_assert_eq(a, 2);
}
