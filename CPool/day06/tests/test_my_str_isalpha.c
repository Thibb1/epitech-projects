/*
** EPITECH PROJECT, 2020
** strcap test
** File description:
** test cap
*/

#include <criterion/criterion.h>

#include <string.h>

int my_str_isalpha(char const *str);

Test(my_str_isalpha, str_isaplha_test)
{
    char src[30] = "bonjour Espece de toto";
    int alpha = my_str_isalpha(src);

    cr_assert_eq(alpha, 0);
}

Test(my_str_isalpha, str_isaplha_test_true)
{
    char src[30] = "bonjourEspecedetoto";
    int alpha = my_str_isalpha(src);

    cr_assert_eq(alpha, 1);
}
