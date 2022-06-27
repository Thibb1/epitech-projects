/*
** EPITECH PROJECT, 2020
** pixel
** File description:
** puts pixels in frame
*/

#include "../include/my_sfml.h"
#include "../include/my.h"

void my_put_pixel(framebuffer_t *framebuffer,
    unsigned int x,
    unsigned int y,
    sfColor color)
{
    if (x > W_W || y > W_H)
        return;
    framebuffer->pixels[(W_W * y + x) * 4 + 0] = color.r;
    framebuffer->pixels[(W_W * y + x) * 4 + 1] = color.g;
    framebuffer->pixels[(W_W * y + x) * 4 + 2] = color.b;
    framebuffer->pixels[(W_W * y + x) * 4 + 3] = color.a;
}

void my_draw_square(framebuffer_t *f, sfVector2u pos, unsigned int s, sfColor c)
{
    for (unsigned int i = 0; i <= s; i++)
        for (unsigned int b = 0; b <= s; b++)
            my_put_pixel(f, pos.x + b, pos.y + i, c);
}

void my_draw_line(framebuffer_t *f, line line)
{
    my_line(f, line.a, line.b, line.color);
    for (int i = (line.thick - 1) / 2; i >= 0; i--) {
        line.a.y += i;
        line.b.y += i;
        my_line(f, line.a, line.b, line.color);
        line.a.y -= 2 * i;
        line.b.y -= 2 * i;
        my_line(f, line.a, line.b, line.color);
    }

}

void my_line(framebuffer_t *f, sfVector2i v, sfVector2i b, sfColor color)
{
    int step;
    float d[2] = {b.x - v.x, b.y - v.y};
    float a[2] = {v.x, v.y};
    if (ABS(d[0]) >= ABS(d[1]))
        step = ABS(d[0]);
    else
        step = ABS(d[1]);
    if (step) {
        d[0] /= step;
        d[1] /= step;
        for (int i = 1; i <= step; a[0] += d[0], a[1] += d[1], i++)
            my_put_pixel(f, (int)a[0], (int)a[1], color);
    }
}

void my_circle(framebuffer_t *f, sfVector2i p, int r, sfColor color)
{
    int x;
    for (int i = p.y - r; i <= p.y + r; i++)
        for (int b = p.x - r; b <= p.x + r; b++) {
            x = (b - p.x) * (b - p.x) + (i - p.y) * (i - p.y);
            (x <= r * r) ? my_put_pixel(f, b, i, color) : 0;
        }
}
