/*
** EPITECH PROJECT, 2020
** my_print_revalpha
** File description:
** prints alphabet reverse
*/

void my_putchar(char c);

int my_print_revalpha(void)
{
    char letter = 'z';

    while (letter >= 'a') {
        my_putchar(letter);
        letter--;
    }
    my_putchar('\n');
    return (0);
}
