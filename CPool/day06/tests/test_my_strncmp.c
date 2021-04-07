/*
** EPITECH PROJECT, 2020
** test my_strstr
** File description:
** test revstr
*/

#include <criterion/criterion.h>

#include <string.h>

int my_strncmp(char const *s1, char const *s2, int n);

Test(my_strncmp, compn_s1_to_s2)
{
    char str1[] = "abzd";
    char str2[] = "abcd";
    int a = my_strncmp(str1, str2, 4);
    int b = strncmp(str1, str2, 4);

    cr_assert_eq(a, b);
}

Test(my_strncmp, compn_same_s1_to_s2)
{
    char str1[] = "abzd";
    char str2[] = "abzd";
    int a = my_strncmp(str1, str2, 3);
    int b = strncmp(str1, str2, 3);

    cr_assert_eq(a, b);
}

Test(my_strncmp, compn_with_n_sup_as_str)
{
    char str1[] = "ab";
    char str2[] = "ab";
    int a = my_strncmp(str1, str2, 4);
    int b = strncmp(str1, str2, 4);

    cr_assert_eq(a, b);
}
