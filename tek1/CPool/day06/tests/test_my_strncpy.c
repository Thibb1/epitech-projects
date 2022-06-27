/*
** EPITECH PROJECT, 2020
** test strcpy
** File description:
** test strcopy
*/

#include <criterion/criterion.h>

#include <string.h>

char *my_strncpy(char *dest, char const *src, int n);

Test(my_strncpy, copy_string_into_dest)
{
    char dest[6] = {0};
    char mydest[6] = {0};

    my_strncpy(mydest, "HelloWorld", 5);
    strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(mydest, dest);
}

Test(my_strncpy, copy_string_into_destb)
{
    char dest[6] = {0};
    char mydest[6] = {0};

    my_strncpy(mydest, "Hel", 6);
    strncpy(dest, "Hel", 6);
    cr_assert_str_eq(mydest, dest);
}
