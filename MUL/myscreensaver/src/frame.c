/*
** EPITECH PROJECT, 2020
** frame
** File description:
** framebuff functs
*/

#include "../include/my.h"
#include "../include/my_sfml.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
    framebuffer_t *frame = malloc(sizeof(framebuffer_t));
    frame->width = width;
    frame->height = height;
    frame->pixels = malloc(width * height * 4);
    return (frame);
}

void framebuffer_destroy(framebuffer_t *framebuffer)
{
    free(framebuffer->pixels);
    free(framebuffer);
}

void create_f(sfRenderWindow *w, framebuffer_t *b, sfTexture *t, sfSprite *s)
{
    sfRenderWindow_setFramerateLimit(w, 30);
    sfSprite_setTexture(s, t, sfTrue);
    if (!t || !b || !s || !w)
        return;
}
