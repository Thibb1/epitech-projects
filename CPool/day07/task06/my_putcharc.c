/*
** EPITECH PROJECT, 2020
** putcharc
** File description:
** puts chars
*/

#include <unistd.h>

void my_putcharc(char c)
{
    write(1, &c, 1);
}
