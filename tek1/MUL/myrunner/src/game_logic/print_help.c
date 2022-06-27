/*
** EPITECH PROJECT, 2020
** print_help.c
** File description:
** print help thats all
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

void print_help(void)
{
    my_printf("Finite runner created with CSFML.\n\nUSAGE\n  ./my_runner");
    my_printf(" map.txt\n\n\nOPTIONS\n  -i\t\tlaunch the game in infinity mo");
    my_printf("de.\n  -h\t\tprint the usage and quit.\n\nUSER INTERACTIONS\n");
    my_printf("  SPACE_KEY\tjump.\n");
}