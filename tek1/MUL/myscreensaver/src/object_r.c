/*
** EPITECH PROJECT, 2020
** sfml functs
** File description:
** erases objts at the end
*/

#include "../include/my_sfml.h"

void object_r(sfRenderWindow *w, framebuffer_t *b, sfTexture *t, sfSprite *s)
{
    framebuffer_destroy(b);
    sfTexture_destroy(t);
    sfSprite_destroy(s);
    sfRenderWindow_destroy(w);
}
