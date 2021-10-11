/*
** EPITECH PROJECT, 2020
** my_is_prime.c
** File description:
** return True if nb prime
*/

int my_is_it_prime(int nb, int i)
{
    i = 3;
    while (i <= (nb / 3)) {
        if (nb % i == 0)
            return (0);
        i += 2;
    }
    return (1);
}

int my_is_prime(int nb)
{
    int i = 3;

    if (nb == 2)
        return (1);
    else if (nb % 2 && nb > 2) {
        return (my_is_it_prime(nb, i));
    }
    return (0);
}
