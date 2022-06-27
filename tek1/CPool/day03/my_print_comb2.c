/*
** EPITECH PROJECT, 2020
** my_print_comb
** File description:
** prints some chars
*/

void my_putchar(char c);

void my_put_nbrr(int nb)
{
    my_putchar(nb / 10 + '0');
    my_putchar(nb % 10 + '0');
}

int my_putcomma(int a)
{
    if (a == 1) {
        my_putchar(',');
        my_putchar(' ');
    }
    return (1);
}

int my_test_coomb(int test_number)
{
    int first_digit;
    int second_digit;
    int a;
    int b;

    first_digit = test_number / 100;
    a = test_number / 10 % 10;
    b = test_number % 10;
    second_digit = a * 10 + b;
    if (first_digit != second_digit)
        return (1);
    return (0);
}

int my_print_comb2(void)
{
    int my_test_digit;
    int a;
    int b;

    b = 0;
    my_test_digit = 0;
    while (my_test_digit <= 9999) {
        a = my_test_digit / 10 % 10;
        if (my_test_coomb(my_test_digit)) {
            b = my_putcomma(b);
            my_put_nbrr(my_test_digit / 100);
            my_putchar(' ');
            my_put_nbrr(a * 10 + my_test_digit % 10);
        }
        if (a * 10 + my_test_digit % 10 == 99)
            my_test_digit = my_test_digit + my_test_digit / 100 + 1;
        my_test_digit++;
    }
    my_putchar('\n');
    return (0);
}
