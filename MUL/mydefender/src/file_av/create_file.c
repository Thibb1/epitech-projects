/*
** EPITECH PROJECT, 2020
** create_file.c
** File description:
** create / opens a file
*/

#include "defender.h"

void create_file(char *filename)
{
    FILE *f = fopen(filename, "w");

    fclose(f);
}