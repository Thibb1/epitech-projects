/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** returns nb
*/

void my_putchar(char c);

int my_check(long long n, int fn, int nb)
{
    if (!nb || (n > 21474836470 && !(fn) || ((fn) && (n > 21474836480)))) {
        return (0);
    } else if (fn)
        return (-n / 10);
    return (n / 10);
}

int my_getnbr(char const *str)
{
    long long n;
    int i;
    int nb;
    int fn;

    i = 0;
    nb = 0;
    n = 0;
    fn = 0;
    while ((str[i]) && (nb < 11) && (!(nb) || (47 < str[i] && str[i] < 58))) {
        if (str[i] == '-') {
            fn = (fn % 2 + 1) % 2;
        } else if (47 < str[i] && str[i] < 58) {
            n = 10 * (n + str[i] - '0');
            nb++;
        }
        i++;
    }
    return (my_check(n, fn, nb));
}
