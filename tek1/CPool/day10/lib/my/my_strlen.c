/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** counts len of str
*/

int my_strlen(char const *str)
{
    int lenght;

    lenght = 0;
    while (str[lenght] != '\0')
        lenght++;
    return (lenght);
}
