/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** put single chars
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
