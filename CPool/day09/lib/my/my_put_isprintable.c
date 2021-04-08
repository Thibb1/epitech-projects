/*
** EPITECH PROJECT, 2020
** put_isprintable.c
** File description:
** put printable char
*/

void my_putnbr_base(int nbr, char const *base);

void my_putchar(char c);

int my_put_isprintable(char c)
{
    my_putchar(92);
    if (c < 16)
        my_putchar('0');
    my_putnbr_base(c, "0123456789abcdef");
}
