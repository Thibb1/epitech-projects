/*
** EPITECH PROJECT, 2020
** tests_str_tools.
** File description:
** test str tools
*/

#include "../include/mytest.h"

Test(my_str_islower, str_lower)
{
    int a = my_str_islower("aAb");
    a = my_str_islower("aba");
    cr_assert_eq(a, 1);
}

Test(my_str_isupper, str_upper)
{
    int a = my_str_isupper("aAb");
    a = my_str_isupper("ABA");
    cr_assert_eq(a, 1);
}

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
