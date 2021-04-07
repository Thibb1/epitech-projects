/*
** EPITECH PROJECT, 2020
** strupper test
** File description:
** test upper
*/

#include <criterion/criterion.h>

#include <string.h>

int my_str_isupper(char const *str);

Test(my_str_isupper, str_isupper_test)
{
    char src[30] = "bonjour Espece de toto";
    int upper = my_str_isupper(src);

    cr_assert_eq(upper, 0);
}

Test(my_str_isupper, str_isupper_test_true)
{
    char src[30] = "BONJOUR";
    int upper = my_str_isupper(src);

    cr_assert_eq(upper, 1);
}
