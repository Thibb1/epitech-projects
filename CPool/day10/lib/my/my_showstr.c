/*
** EPITECH PROJECT, 2020
** showstr
** File description:
** prints text but not not ascii
*/

int my_is_printable_one(char c);

void my_putchar(char c);

int my_is_printable(char c);

int my_put_isprintable(char c);

int my_showstr(char const *str)
{
    int i = 0;
    for (; str[i]; i++) {
        if (my_is_printable(str[i]))
            my_put_isprintable(str[i]);
        else
            my_putchar(str[i]);
    }
    return (0);
}
