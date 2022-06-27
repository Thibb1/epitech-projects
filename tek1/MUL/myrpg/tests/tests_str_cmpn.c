/*
** EPITECH PROJECT, 2020
** tests_strncmp.c
** File description:
** test my_strncmp
*/

#include "my_test.h"

Test(my_strncmp, my_strncmp_s1_to_s2_test)
{
    char str1[] = "Hello";
    char str2[] = "hell no";

    cr_assert(my_strncmp(str1, str2, 4));
}

Test(my_strncmp, my_strncmp_same_s1_to_s2_test)
{
    char str1[] = "Hello";
    char str2[] = "Hello";

    cr_assert_eq(my_strncmp(str1, str2, 3), 0);
}

Test(my_strncmp, my_strncmp_with_n_sup_as_str_test)
{
    char str1[] = "No";
    char str2[] = "No";

    cr_assert_eq(my_strncmp(str1, str2, 4), 0);
}