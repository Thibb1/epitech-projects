/*
** EPITECH PROJECT, 2020
** tests_str_tools.
** File description:
** test str tools
*/

#include "my_test.h"

Test(my_strcat, str_cat)
{
    char src[10] = "abc";
    cr_assert_str_eq(my_strcat(src, "ax"), "abcax");
}

Test(my_putnisprintable, putnprint, .init = rstd)
{
    int a = my_putnisprintable(10, 4);
    cr_assert_stdout_eq_str("\\010");
}
