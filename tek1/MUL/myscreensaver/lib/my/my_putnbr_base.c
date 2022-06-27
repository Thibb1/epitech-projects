/*
** EPITECH PROJECT, 2020
** my_putnbr
** File description:
** decimal into nb with certain base
*/

void my_putchar(char c);

int my_putnbr_base(int nbr, char const *base);

int my_strlen(char const *str);

int my_putnbr_base(int nbr, char const *base)
{
    int taillebase = my_strlen(base);

    if (nbr < 0) {
        my_putchar('-');
        my_putnbr_base(-nbr, base);
    } else if (!nbr)
        return (0);
    else
        my_putnbr_base(nbr / taillebase, base);
    my_putchar(base[nbr % taillebase]);
    return (0);
}
