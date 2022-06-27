/*
** EPITECH PROJECT, 2020
** check prime
** File description:
** checks if prime
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
