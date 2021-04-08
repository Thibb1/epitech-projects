/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** returns nb
*/

void my_putchar(char c);

int my_is_int(long long n, int fn, int nb);

int my_getnbr(char const *str)
{
    long long n = 0;
    int i = 0;
    int nb = 0;
    int fn = 0;

    while ((str[i]) && (nb < 11) && (!(nb) || (47 < str[i] && str[i] < 58))) {
        if (str[i] == '-') {
            fn = (fn % 2 + 1) % 2;
        } else if (47 < str[i] && str[i] < 58) {
            n = 10 * (n + str[i] - '0');
            nb++;
        }
        i++;
    }
    return (my_is_int(n, fn, nb));
}
