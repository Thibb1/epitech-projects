/*
** EPITECH PROJECT, 2020
** anim1.c
** File description:
** amins list
*/

#include "../include/my.h"
#include "../include/my_sfml.h"

void add_triangle(framebuffer_t *f)
{
    static Vector2d a = {W_W / 3, W_H - W_H / 5};
    static Vector2d b = {W_W - W_W / 3, W_H / 1.5};
    const double v = 60.0 * PI / 180.0;
    const Vector2d c = {cos(v) * (b.x - a.x) + sin(v) * (b.y - a.y) + a.x,
        sin(-v) * (b.x - a.x) + cos(v) * (b.y - a.y) + a.y};
    line line = {{0, 0}, {c.x, c.y}, {0, 0, 175, 205}, 3};
    static double x = 0;

    triangle(f, a, b, line);
    x += 0.1;
    a.x -= sin(x) * 6;
    a.y -= sin(x) * 6;
    b.x += sin(x) * 6;
    b.y += sin(x) * 6;
}

void add_square(framebuffer_t *f)
{
    int s = rand() % 200 + 50;
    int alpha = rand() % 106 + 150;
    sfVector2u pos = {rand() % (W_W - s), rand() % (W_H - s)};
    sfColor c = {rand() % 256, rand() % 256, rand() % 256, alpha};

    my_draw_square(f, pos, s, c);
}

void add_lines(framebuffer_t *f)
{
    static line lina = {{0, 0}, {W_W, 0}, {0, 0, 0, 255}, 3};
    static line linb = {{0, 0}, {W_W, 0}, {0, 0, 0, 255}, 3};
    static line linc = {{0, 0}, {W_W, 0}, {0, 0, 0, 255}, 3};

    lina.color.r += lina.color.g >= 246 ? 10 : 0;
    lina.color.r = linb.color.b = linc.color.g = lina.color.r;
    lina.color.g += lina.color.b >= 246 || lina.color.g >= 246 ? 10 : 0;
    lina.color.g = linb.color.r = linc.color.b = lina.color.g;
    lina.color.b = linb.color.g = linc.color.r = lina.color.b + 10;
    my_draw_line(f, lina);
    my_draw_line(f, linb);
    my_draw_line(f, linc);
    lina.a.y = lina.b.y = (lina.a.y + 5) % W_H;
    linb.a.y = linb.b.y = (linb.a.y + 4) % W_H;
    linc.a.y = linc.b.y = (linc.a.y + 3) % W_H;
}

void pop_circle(framebuffer_t *f)
{
    static float x = 0;
    static sfColor a = {0, 0, 0, 0};
    sfVector2i p = {cos(x) * (W_W - 400) / 2 + W_W / 2,
        sin(10 * x) * (W_H - 250) / 2 + W_H / 2};
    static sfColor c = {0, 0, 0, 255};

    my_circle(f, p, (0.02 + ABS(cos(x))) * 80, c);
    c.b += a.b ? -10 : 10;
    if (c.b >= 246) {
        c.g += a.g ? -20 : 20;
        a.b = 1;
        if (c.g >= 240) {
            c.r += a.r ? -20 : 20;
            a.r = c.r >= 240 || (a.r && c.r >= 140) ? 1 : 0;
            a.g = 1;
        } else if (c.g <= 130)
            a.g = 0;
    } else if (c.b == 130)
        a.b = 0;
    x += 0.02;
}

void fractal(framebuffer_t *f)
{
    static mandel d = {{-2.5, -2.0}, {1.5, 2.0}, {W_W, W_H}, {0, 0}, {0, 0},
        {0, 0}, {0, 0}, 0, 20, 255, 2};
    static double x = 0;
    Vector2d pixel = {(d.cmax.x - d.cmin.x) / d.imax.x,
        (d.cmax.y - d.cmin.y) / d.imax.y};
    for (d.p.y = 0; d.p.y < d.imax.y; d.p.y++) {
        d.c.y = d.cmin.y + d.p.y * pixel.y;
        if (fabs(d.c.y) < pixel.y / 2)
            d.c.y = 0.0;
        for (d.p.x = 0; d.p.x < d.imax.x; d.p.x++) {
            d.c.x = d.cmin.x + d.p.x * pixel.x;
            d.z.x = d.z.y = d.z2.x = d.z2.y = 0;
            pixel_it(f, d);
        }
    }
    x += 0.1;
    d.cmin.x += sin(x) / W_W * 30;
    d.cmin.y += sin(x) / W_H * 40;
    d.cmax.x -= sin(x) / W_W * 40;
    d.cmax.y -= sin(x) / W_H * 40;
}
