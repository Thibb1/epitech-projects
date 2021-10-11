/*
** EPITECH PROJECT, 2020
** CSFML
** File description:
** loads graph engine and output a window
*/

#include "../include/my.h"
#include "../include/my_sfml.h"

void (*p[20])(framebuffer_t *f);

void add_objects(framebuffer_t *f, sfTexture *t, int nb, int i)
{
    int x = 0;
    if (i == 1 && nb == 2)
        (*p[nb]) (f);
    if (nb != 2)
        (*p[nb]) (f);
    sfTexture_updateFromPixels(t, f->pixels, W_W, W_H, 0, 0);
    for (int i = 0; i < W_W; i++)
        for (int b = 0; b < W_H; b++) {
            x = (W_W * b + i) * 4 + 3;
            f->pixels[x] -= f->pixels[x] > 50 ? 10 : f->pixels[x];
        }
}

void init_p(void)
{
    p[2] = add_triangle;
    p[3] = add_square;
    p[4] = add_lines;
    p[5] = fractal;
    p[1] = pop_circle;
}

void event_window(sfRenderWindow *w, sfEvent event, int *nb)
{
    while (sfRenderWindow_pollEvent(w, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(w);
        if (event.type == sfEvtKeyPressed) {
            *nb += event.key.code == sfKeyRight;
            *nb -= event.key.code == sfKeyLeft;
        }
    }
}

void window(int nb)
{
    sfVideoMode m = {W_W, W_H, 32};
    sfEvent event;
    sfRenderWindow *window;
    sfTexture *texture = sfTexture_create(W_W, W_H);
    sfSprite *sprite = sfSprite_create();
    framebuffer_t *fbuf = framebuffer_create(W_W, W_H);
    int i = 0;
    init_p();
    srand(time(NULL));
    window = sfRenderWindow_create(m, "My_Screensaver",
        sfResize | sfClose, NULL);
    create_f(window, fbuf, texture, sprite);
    while (sfRenderWindow_isOpen(window)) {
        event_window(window, event, &nb);
        add_objects(fbuf, texture, ABS(nb) % 5 + 1, i++ % 2);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    object_r(window, fbuf, texture, sprite);
}
