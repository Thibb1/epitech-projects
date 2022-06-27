/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** returns lenght of str
*/

int my_strlen(char const *str)
{
    int lenght = 0;
    for (; str[lenght]; lenght++);
    return (lenght);
}
