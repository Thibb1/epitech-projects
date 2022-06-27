/*
** EPITECH PROJECT, 2020
** prime sup
** File description:
** returns prime sup
*/

int my_find_prime_sup(int nb);

int my_check_prime(int nb, int i)
{
    while (i <= (nb / 3)) {
        if (nb % i == 0)
            return (my_find_prime_sup(nb + 2));
        i += 2;
    }
    return (nb);
}

int my_find_prime_sup(int nb)
{
    if (nb <= 2)
        return (2);
    else if (nb % 2) {
        return (my_check_prime(nb, 3));
    }
    return (my_find_prime_sup(nb + 1));
}
