/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** check input and calls funcitons
*/

#include "../include/my.h"
#include "../include/my_sfml.h"

void print_help(void)
{
    my_printf("animation rendering in a CSFML window.\n\nUSAGE\n       ./my_s");
    my_printf("creen");
    my_printf("saver\t[OPTIONS] animation_id\n\tanimation_id\tID of the anima");
    my_printf("tion to process (between 1 and 20).\n\nOPTIONS\n\t-d\t\tprint ");
    my_printf("the description of all the animations and quit.\n\t-h\t\tprint");
    my_printf(" the usage and quit.\n\nUSER INTERACTIONS\n\tLE");
    my_printf("FT_ARROW\tswitch to the previous animation.\n\tRIGHT_ARROW\tsw");
    my_printf("itch to the next animation.\n");
}

void print_description(void)
{
    my_printf("1: blue isocele filled triangles growing.\n");
    my_printf("2: squares with random size and color fading out.\n");
    my_printf("3: horizontal lines cycling trought the window.\n");
    my_printf("4: Mendelbrot set zooming in and out.\n");
    my_printf("5: circles following a sin curve and growing in and out.\n");
}

int main(int ac, char *av[])
{
    int nb;
    if (ac != 2) {
        write(2, "Wrong number of arguments\n", 26);
        return (84);
    }
    if (!my_strcmp(av[1], "-h")) {
        print_help();
    } else if (!my_strcmp(av[1], "-d")) {
        print_description();
    } else {
        nb = my_getnbr(av[1]);
        if (nb > 0 && nb < 6)
            window(nb);
        else {
            write(2, "Wrong ID\n", 9);
            return (84);
        }
    }
}
