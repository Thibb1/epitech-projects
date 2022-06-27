/*
** EPITECH PROJECT, 2020
** my_evil_str
** File description:
** swap char
*/

void my_putchar(char c);

char *my_evil_str(char *str)
{
    int length;
    int i = 0;
    char tempchar;

    for (length = 0; str[length] != '\0'; length++);
    while (i < length - i - 1) {
        tempchar = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = tempchar;
        i++;
    }
    return (&str[0]);
}
