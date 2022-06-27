/*
** EPITECH PROJECT, 2021
** my_grep_str.c
** File description:
** returns str pointer to location of a char in a str
*/

char *my_grep_str(char reg, char *str)
{
    while (*str && *str != reg)
        (void)*str++;
    return (++str);
}