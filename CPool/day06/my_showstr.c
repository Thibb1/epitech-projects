/*
** EPITECH PROJECT, 2020
** showstr
** File description:
** prints text but not not ascii
*/

void my_putchar(char c);

int my_strlend(char const *str)
{
    int length = 0;

    while (str[length])
        length++;
    return (length);
}

void my_putnbr_based(int nbr, char const *base)
{
    int taillebase = my_strlend(base);

    if (!nbr)
        return;
    else
        my_putnbr_based(nbr / taillebase, base);
    my_putchar(base[nbr % taillebase]);
    return;
}

int my_is_printable_oneb(char c)
{
    if (!(c >= ' ' && c <= '~'))
        return (1);
    return (0);
}

void my_putnonascii(char c)
{
    my_putchar(92);
    if (c < 16)
        my_putchar('0');
    my_putnbr_based(c, "0123456789abcdef");
}

int my_showstr(char const *str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (my_is_printable_oneb(str[i]))
            my_putnonascii(str[i]);
        else
            my_putchar(str[i]);
    }
    return (0);
}
