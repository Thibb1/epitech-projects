/*
** EPITECH PROJECT, 2020
** prime sup
** File description:
** returns prime sup
*/

int my_check_prime(int nb, int i);

int my_find_prime_sup(int nb)
{
    if (nb <= 2)
        return (2);
    else if (nb % 2) {
        return (my_check_prime(nb, 3));
    }
    return (my_find_prime_sup(nb + 1));
}
