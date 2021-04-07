/*
** EPITECH PROJECT, 2020
** my_print_digits
** File description:
** prints all numbers
*/

void my_putchar(char c);

int my_print_digits(void)
{
    char digit = '0';

    while (digit <= '9') {
        my_putchar(digit);
        digit++;
    }
    my_putchar('\n');
    return (0);
}
