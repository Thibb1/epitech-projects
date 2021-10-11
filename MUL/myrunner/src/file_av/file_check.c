/*
** EPITECH PROJECT, 2020
** file_check.c
** File description:
** check file
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

int file_check(char *path)
{
    int descriptor = open(path, O_RDONLY);
    if (descriptor == - 1)
        return (ERROR);
    close(descriptor);
    return (SUCCESS);
}