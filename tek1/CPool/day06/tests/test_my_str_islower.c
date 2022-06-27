/*
** EPITECH PROJECT, 2020
** strcap test
** File description:
** test cap
*/

#include <criterion/criterion.h>

#include <string.h>

int my_str_islower(char const *str);

Test(my_str_islower, str_islower_test)
{
    char src[30] = "bonjour Espece de toto";
    int lower = my_str_islower(src);

    cr_assert_eq(lower, 0);
}

Test(my_str_islower, str_islower_test_true)
{
    char src[30] = "bonjour";
    int lower = my_str_islower(src);

    cr_assert_eq(lower, 1);
}
