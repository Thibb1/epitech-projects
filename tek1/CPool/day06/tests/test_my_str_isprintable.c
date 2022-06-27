/*
** EPITECH PROJECT, 2020
** isprintable test
** File description:
** test isprintable
*/

#include <criterion/criterion.h>

#include <string.h>

int my_str_isprintable(char const *str);

Test(my_str_isprintable, str_isprintable_test)
{
    char src[30] = "bonjour Espèçe de toto";
    int printable = my_str_isprintable(src);

    cr_assert_eq(printable, 0);
}

Test(my_str_isprintable, str_isprintable_test_true)
{
    char src[30] = "BONJOUR";
    int printable = my_str_isprintable(src);

    cr_assert_eq(printable, 1);
}
