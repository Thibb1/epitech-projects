/*
** EPITECH PROJECT, 2020
** test getnbr
** File description:
** test the my_getnbr func
*/

#include <criterion/criterion.h>

int my_getnbr_base(char const *str, char const *base);

Test(my_getnbr_base, putnbr_hex_to_dec)
{
    char base[] = "0123456789ABCDEF";
    char nbr[] = "--54245526";
    int a;

    a = my_getnbr_base(nbr, base);
    cr_assert_eq(a, 1411667238);
}

Test(my_getnbr_base, putnbr_nb_sup_to_base)
{
    char base[] = "01234";
    char nbr[] = "---54245526";
    int a;

    a = my_getnbr_base(nbr, base);
    cr_assert_eq(a, 0);
}

Test(my_getnbr_base, putnbr_bi_to_dec)
{
    char base[] = "01";
    char nbr[] = "10000000";
    int a;

    a = my_getnbr_base(nbr, base);
    cr_assert_eq(a, 128);
}

Test(my_getnbr_base, no_nb_in_str)
{
    char base[] = "012345";
    char nbr[] = " é";
    int a;

    a = my_getnbr_base(nbr, base);
    cr_assert_eq(a, 0);
}
