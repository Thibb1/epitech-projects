/*
** EPITECH PROJECT, 2020
** tests_strn_utils.c
** File description:
** test strn utils
*/

#include <string.h>
#include "../include/mytest.h"

Test(my_strncmp, compn_s1_to_s2)
{
    char str1[] = "abzd";
    char str2[] = "abcd";
    int a = my_strncmp(str1, str2, 4);
    cr_assert(a);
}

Test(my_strncmp, compn_same_s1_to_s2)
{
    char str1[] = "abzd";
    char str2[] = "abzd";
    int a = my_strncmp(str1, str2, 3);
    cr_assert_eq(a, 0);
}

Test(my_strncmp, compn_with_n_sup_as_str)
{
    char str1[] = "ab";
    char str2[] = "ab";
    int a = my_strncmp(str1, str2, 4);
    cr_assert_eq(a, 0);
}

Test(my_strncpy, copy_string_into_dest)
{
    char mydest[6] = {0};
    my_strncpy(mydest, "HelloWorld", 5);
    cr_assert_str_eq(mydest, "Hello");
}

Test(my_strncpy, copy_string_into_destb)
{
    char mydest[6] = {0};
    my_strncpy(mydest, "Hel", 6);
    cr_assert_str_eq(mydest, "Hel");
}
