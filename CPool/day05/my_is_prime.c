/*
** EPITECH PROJECT, 2020
** is prime
** File description:
** return 1 or 0
*/

int my_is_it_prime(int nb, int i);

int my_is_prime(int nb)
{
    if (nb == 2)
        return (1);
    else if (nb % 2 && nb > 2) {
        return (my_is_it_prime(nb, 3));
    }
    return (0);
}

int my_is_it_prime(int nb, int i)
{
    while (i <= (nb / 3)) {
        if (nb % i == 0)
            return (0);
        i += 2;
    }
    return (1);
}