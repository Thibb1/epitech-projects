/*
** EPITECH PROJECT, 2020
** test putnbr
** File description:
** test the my_putnbr func
*/

#include <criterion/criterion.h>

int my_putnbr_base(int nbr, char const *base);

Test(my_putnbr_base, putnbr_hex)
{
    char base[17] = "0123456789ABCDEF";
    int nbr = 2353;

    nbr = my_putnbr_base(nbr, base);
    cr_assert_null(nbr);
}

Test(my_putnbr_base, putnbr_base_two)
{
    char base[] = "01234";
    int nbr = -54245526;

    nbr = my_putnbr_base(nbr, base);
    cr_assert_null(nbr);
}
