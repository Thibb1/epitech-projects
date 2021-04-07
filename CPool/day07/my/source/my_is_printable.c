/*
** EPITECH PROJECT, 2020
** str_isprintable
** File description:
** check if char is printable
*/

int my_is_printable(char c)
{
    if (!(c >= ' ' && c <= '~'))
        return (1);
    return (0);
}
