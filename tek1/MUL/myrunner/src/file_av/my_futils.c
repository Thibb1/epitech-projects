/*
** EPITECH PROJECT, 2020
** my_futils.c
** File description:
** opens a file
*/

#include "../include/my.h"

int my_fopen(const char *filepath, const char accesmode)
{
    int descriptor = -1;
    if (accesmode == 'r')
        descriptor = open(filepath, O_RDONLY);
    else if (accesmode == 'w')
        descriptor = open(filepath, O_WRONLY);
    else
        descriptor = open(filepath, O_RDWR);
    if (descriptor == -1)
        my_ferror("Could not open the file");
    return (descriptor);
}

int my_fclose(int file)
{
    return (close(file));
}
