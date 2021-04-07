/*
** EPITECH PROJECT, 2020
** myshowmem
** File description:
** shows mem of arr
*/

int my_putstr(char const *str);

int my_putnbr_base(int nbr, char const *base);

void my_putchar(char c);

int my_is_printable(char const c);

void my_memadrr(char const *stc, int size)
{
    int b;
    char base[] = "0123456789ABCDEF";

    my_putstr("00");
    my_putnbr_base(stc, base);
    my_putstr(": ");
    for (b = 0; b < size; b++) {
        if (stc[b] < ' ')
            my_putstr("00");
        else
            my_putnbr_base(stc[b], base);
        if (b % 2)
            my_putchar(' ');
    }
    for (b = 0; b < size; b++) {
        if (my_is_printable(stc[b]))
            my_putchar('.');
        else
            my_putchar(stc[b]);
    }
}

int my_showmem(char const *str, int size)
{
    int a;
    char *stb = str;

    for (a = 0; size > a; a++) {
        my_memadrr(stb, 16);
        stb += 16;
        my_putchar('\n');
    }
    return (0);
}
