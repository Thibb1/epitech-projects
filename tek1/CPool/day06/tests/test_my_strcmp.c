/*
** EPITECH PROJECT, 2020
** test my_strstr
** File description:
** test revstr
*/

#include <criterion/criterion.h>

#include <string.h>

int my_strcmp(char const *s1, char const *s2);

Test(my_strcmp, comp_s1_to_s2)
{
    char str1[] = "abzd";
    char str2[] = "abcd";
    int a = my_strcmp(str1, str2);
    int b = strcmp(str1, str2);

    cr_assert_eq(a, b);
}

Test(my_strcmp, comp_same_s1_to_s2)
{
    char str1[] = "abzd";
    char str2[] = "abzd";
    int a = my_strcmp(str1, str2);
    int b = strcmp(str1, str2);

    cr_assert_eq(a, b);
}
