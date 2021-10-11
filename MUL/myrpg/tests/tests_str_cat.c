/*
** EPITECH PROJECT, 2020
** tests_str_cat.c
** File description:
** test str cat
*/

#include "my_test.h"

Test(my_strncat, my_strncat_test)
{
    char src[30] = "ab";
    my_strncat(src, "acb", 2);

    cr_assert_str_eq("abac", src);
}

Test(my_strcat, my_strcat_test)
{
    char src[10] = "hell";

    cr_assert_str_eq(my_strcat(src, "o"), "hello");
}