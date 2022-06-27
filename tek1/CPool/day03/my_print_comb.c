/*
** EPITECH PROJECT, 2020
** my_print_comb
** File description:
** prints some chars
*/

void my_putchar(char c);

void my_puut_nbr(int nb)
{
    my_putchar(nb / 100 + '0');
    my_putchar(nb / 10 % 10 + '0');
    my_putchar(nb % 10 + '0');
    if (nb != 789) {
        my_putchar(',');
        my_putchar(' ');
    }
}

int myy_test_comb(int test_number)
{
    int a;
    int b;
    int c;

    a = test_number / 100;
    b = test_number / 10 % 10;
    c = test_number % 10;
    if ((a < b) && (b < c) && (a != b != c))
        return (1);
    return (0);
}

int my_print_comb(void)
{
    int my_test_digit;

    my_test_digit = 0;
    while (my_test_digit <= 999) {
        if (myy_test_comb(my_test_digit))
            my_puut_nbr(my_test_digit);
        my_test_digit++;
    }
    my_putchar('\n');
    return (0);
}
