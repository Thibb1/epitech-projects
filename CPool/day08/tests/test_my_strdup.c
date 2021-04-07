/*
** EPITECH PROJECT, 2020
** test_my_strdup
** File description:
** test my_strdup
*/

#include <criterion/criterion.h>

char *my_strdup(char const *src);

Test(my_strdup, test_strdup)
{
    cr_assert_str_eq(my_strdup("test"), "test");
}
