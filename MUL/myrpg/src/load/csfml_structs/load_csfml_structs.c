/*
** EPITECH PROJECT, 2021
** load_csfml_structs.c
** File description:
** load_csfml_structs.c
*/

#include "my_rpg.h"

sfIntRect make_rectangle(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}