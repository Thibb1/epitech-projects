/*
** EPITECH PROJECT, 2020
** strcap test
** File description:
** test cap
*/

#include <criterion/criterion.h>

#include <string.h>

char *my_strcapitalize(char *str);

Test(my_strcapitalize, str_capitalize_test)
{
    char src[30] = "bonJour-EspECe de 12toto";

    my_strcapitalize(src);
    cr_assert_str_eq(src, "Bonjour-Espece De 12toto");
}
