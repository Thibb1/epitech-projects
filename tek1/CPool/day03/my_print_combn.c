/*
** EPITECH PROJECT, 2020
** my_print_comb
** File description:
** prints some chars
*/

void my_putchar(char c);

int my_pow(int nb, int exposant)
{
    if (exposant == 0)
        return (1);
    else if (exposant == 1)
        return (nb);
    else
        return (nb * my_pow(nb, exposant - 1));
}

int my_putt_nbr(int nb, int n, int a)
{
    if (a == 1) {
        my_putchar(',');
        my_putchar(' ');
    }
    while (n > 0) {
        my_putchar((nb / my_pow(10, n - 1) % 10) + '0');
        n--;
    }
    return (1);
}

int my_test_comb(int test_number, int n)
{
    int a;
    int b;

    a = test_number / (my_pow(10, n - 1)) % 10;
    b = test_number / (my_pow(10, n - 2)) % 10;
    if (a < b && (a != b)) {
        if (n > 2)
            return (my_test_comb(test_number, n - 1));
        return (1);
    }
    return (0);
}

int my_print_combn(int n)
{
    int my_comma_var;
    int my_test_digit;

    my_test_digit = 0;
    my_comma_var = 0;
    while (my_test_digit <= (my_pow(10, n) - 1))
    {
        if (my_test_comb(my_test_digit, n))
            my_comma_var = my_putt_nbr(my_test_digit, n, my_comma_var);
        my_test_digit++;
    }
    my_putchar('\n');
    return (0);
}
