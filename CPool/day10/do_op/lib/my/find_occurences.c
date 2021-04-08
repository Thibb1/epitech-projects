/*
** EPITECH PROJECT, 2020
** find_occurences
** File description:
** find occ of a letter
*/

float find_occurences(char const *str, char const c)
{
    float nb = 0;

    for (int i = 0; str[i]; i++)
        if (c == str[i])
            nb++;
        else if (c >= 'A' && c <= 'Z' && str[i] == c + ' ')
            nb++;
    return (nb);
}
