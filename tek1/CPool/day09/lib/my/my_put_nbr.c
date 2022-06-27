/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** display possibles values
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    long tamp;

    if (nb < 0) {
        my_putchar('-');
        tamp = (long)nb;
        tamp = (-tamp) % 10;
        if (nb < -9)
            my_put_nbr(-(nb / 10));
        my_putchar(tamp + '0');
    } else if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    } else {
        my_putchar(nb + '0');
    }
    return (0);
}
