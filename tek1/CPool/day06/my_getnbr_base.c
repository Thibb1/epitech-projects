/*
** EPITECH PROJECT, 2020
** my_getnbr_base
** File description:
** gets a number and convert to base 10
*/

int my_strlena(char const *base)
{
    int length = 0;

    while (base[length])
        length++;
    return (length);
}

my_putnbr_dec(int *nbr, int nb, int length)
{
    int rep = 0;
    int mypower = 1;
    int j;

    for (j = nb - 1; j >= 0; j--) {
        if (nbr[j] >= length)
            return (0);
        rep += mypower * nbr[j];
        mypower *= length;
    }
    return (rep);
}

int my_getnbr_base(char const *str, char const *base)
{
    int n[100] = {0};
    int nb = 0;
    int fn = 0;
    int i = 0;

    while (str[i] && nb < 11) {
        if (str[i] == '-') {
            fn = (fn % 2 + 1) % 2;
        } else if (str[i] >= '0' && str[i] <= 'Z') {
            n[nb] = str[i] - '0';
            nb++;
        }
        i++;
    }
    i = my_strlena(base);
    if (!nb)
        return (0);
    else if (fn)
        return (-my_putnbr_dec(n, nb, i));
    return (my_putnbr_dec(n, nb, i));
}
