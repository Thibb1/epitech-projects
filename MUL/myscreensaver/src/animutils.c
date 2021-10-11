/*
** EPITECH PROJECT, 2020
** mandel.c
** File description:
** mandelbrot set utilites
*/

#include "../include/my.h"
#include "../include/my_sfml.h"

void triangle(framebuffer_t *f, Vector2d a, const Vector2d b, line line)
{
    Vector2d z = {b.x - a.x, b.y - a.y};
    int step;
    if (ABS(z.x) >= ABS(z.y))
        step = ABS(z.x);
    else
        step = ABS(z.y);
    if (step) {
        z.x /= step;
        z.y /= step;
        for (int i = 1; i <= step; a.x += z.x, a.y += z.y, i++) {
            line.a.x = a.x;
            line.a.y = a.y;
            my_draw_line(f, line);
        }
    }
}

sfColor getcolor(mandel d)
{
    sfColor color = {d.i / 2 * 255 / d.mit, d.i / 3 * 255 / d.mit,
        d.i * 255 / d.mit, 255};
    return (color);
}

void pixel_it(framebuffer_t *f, mandel d)
{
    for (d.i = 0; d.i < d.mit && (d.z2.x + d.z2.y) < d.r*d.r; d.i++) {
        d.z.y = 2 * d.z.x * d.z.y + d.c.y;
        d.z.x = d.z2.x - d.z2.y + d.c.x;
        d.z2.x = d.z.x * d.z.x;
        d.z2.y = d.z.y * d.z.y;
    }
    if (d.i == d.mit)
        my_put_pixel(f, d.p.x, d.p.y, sfWhite);
    else {
        my_put_pixel(f, d.p.x, d.p.y, getcolor(d));
    }
}
