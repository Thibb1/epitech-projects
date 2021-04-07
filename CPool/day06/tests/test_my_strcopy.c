/*
** EPITECH PROJECT, 2020
** test strcpy
** File description:
** test strcopy
*/

#include <criterion/criterion.h>

char *my_strcpy(char *dest, char const *src);

Test(my_strcpy, copy_string_into_dest)
{
    char dest[6] = {0};

    my_strcpy(dest, "Hello");
    cr_assert_str_eq("Hello", dest);
}
