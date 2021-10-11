/*
** EPITECH PROJECT, 2020
** unload_text.c
** File description:
** text unloading
*/

#include "../../../include/my.h"
#include "../../../include/my_sfml.h"

void unload_text(objects ob)
{
    for (int i = 0; i < TEXT_NB; i++)
        sfText_destroy(ob.text[i].text);
    sfFont_destroy(ob.font);
}