/*
** EPITECH PROJECT, 2020
** my_is_printable.c
** File description:
** return True if c is printable
*/

int my_is_printable(char c)
{
    if (!(c >= ' ' && c <= '~'))
        return (1);
    return (0);
}
