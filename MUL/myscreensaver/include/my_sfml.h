/*
** EPITECH PROJECT, 2020
** sfml advenced functions
** File description:
** adds libs for graphical display
*/
#ifndef MY_SFML
#define MY_SFML
#define FRAMERATE 30
#define W_W 1920
#define W_H 1040
#define PI 3.14159265
#include <SFML/Graphics.h>
#include <SFML/Window.h>
struct framebuffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;

typedef struct line_s {
        sfVector2i a;
        sfVector2i b;
        sfColor color;
        int thick;
} line;
typedef struct Vector2d_s {
    double x;
    double y;
} Vector2d;
typedef struct mandel {
    Vector2d cmin;
    Vector2d cmax;
    const sfVector2i imax;
    Vector2d z;
    Vector2d z2;
    Vector2d c;
    Vector2d p;
    double i;
    const int mit;
    const int maxcolor;
    const double r;
} mandel;
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);

void window(int nb);
void create_f(sfRenderWindow*, framebuffer_t *, sfTexture*, sfSprite*);
void event_window(sfRenderWindow *w, sfEvent event, int *nb);
void add_objects(framebuffer_t *f, sfTexture *t, int nb, int i);
void framebuffer_destroy(framebuffer_t *framebuffer);
void object_r(sfRenderWindow*, framebuffer_t *, sfTexture*, sfSprite*);

void my_put_pixel(framebuffer_t *, unsigned int, unsigned int, sfColor);
void my_draw_square(framebuffer_t *, sfVector2u, unsigned int, sfColor);
void my_draw_line(framebuffer_t *, line line);
void my_line(framebuffer_t *f, sfVector2i v, sfVector2i b, sfColor color);
void my_circle(framebuffer_t *, sfVector2i p, int r, sfColor color);

void add_triangle(framebuffer_t *f);
void add_square(framebuffer_t *f);
void add_lines(framebuffer_t *f);
void pop_circle(framebuffer_t *f);
void fractal(framebuffer_t *f);

sfColor getcolor(mandel d);
void pixel_it(framebuffer_t *f, mandel d);
void triangle(framebuffer_t *f, Vector2d a, const Vector2d b, line line);
#endif
