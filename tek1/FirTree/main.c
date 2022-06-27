/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** calls other functions
*/

#include <unistd.h>

void tree(int tree_height);

void my_putchar(char c)
{
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    tree(5);
    return (0);
}