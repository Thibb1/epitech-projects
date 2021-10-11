/*
** EPITECH PROJECT, 2020
** my_putnbrbase.c
** File description:
** nbr dec to base base
*/

#include "../../include/my.h"

int b_put(const unsigned int nb, const char c, int count)
{
    if (c == 'b')
        count += my_putnbrbase(nb, "01");
    if (c == 'x' || c == 'p')
        count += my_putnbrbase(nb, "0123456789abcdef");
    if (c == 'X')
        count += my_putnbrbase(nb, "0123456789ABCDEF");
    if (c == 'o')
        count += my_putnbrbase(nb, "01234567");
    if (c == 'u')
        count += my_putnbrbase(nb, "0123456789");
    return (count);
}

int my_putnbrbase(unsigned int nbr, char const *base)
{
    int count = 0;
    int tbase = my_strlen(base);
    unsigned int lnb = nbr;
    char rnb[200];
    for (; lnb; lnb /= tbase)
        rnb[count++] = base[lnb % tbase];
    if (nbr == 0)
        rnb[count++] = '0';
    rnb[count] = 0;
    for (int i = count - 1; i >= 0; i--)
        my_putchar(rnb[i]);
    return (count);
}
