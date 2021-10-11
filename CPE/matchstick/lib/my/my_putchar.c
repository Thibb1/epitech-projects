/*
** EPITECH PROJECT, 2020
** my_putchar.c
** File description:
** put a char on stdout
*/

#include <unistd.h>

int my_putchar(int fd, int c)
{
    write(fd, &c, 1);
    return (1);
}
