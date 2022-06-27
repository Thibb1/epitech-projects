/*
** EPITECH PROJECT, 2020
** my_print_alpha.c
** File description:
** returns alphabet
*/

void my_putchar(char c);

int my_print_alpha(void)
{
    char letter = 'a';

    while (letter <= 'z') {
        my_putchar(letter);
        letter++;
    }
    my_putchar('\n');
    return (0);
}
