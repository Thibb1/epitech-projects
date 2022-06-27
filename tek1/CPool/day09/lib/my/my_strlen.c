/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** counts len of str
*/

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0')
        length++;
    return (length);
}
