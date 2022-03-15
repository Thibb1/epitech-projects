/*
** EPITECH PROJECT, 2020
** main_loop.c
** File description:
** basic loop that calls other loops
*/

#include "defender.h"

void draw_shop(window *win, shop *sh)
{
    sfRenderWindow_drawRectangleShape(win->rw, sh[0].outline, NULL);
    for (int i = 0; i < sh[0].nb_but; i++)
        sfRenderWindow_drawRectangleShape(win->rw, sh[0].but[i].rect, NULL);
    for (int i = 0; i < sh[0].nb_text; i++)
        sfRenderWindow_drawText(win->rw, sh[0].text[i].text, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawText(win->rw, sh[1].text[i].text, NULL);
    for (int i = 0; i < 8; i++)
        sfRenderWindow_drawCircleShape(win->rw, sh[0].shapes[i], NULL);
}

void draw_lvl(window *win, assets *as)
{
    enemy *current = as->head;
    tower *curr = as->t_head;

    for (int i = 0; i < as->lvl.nb_cases; i++)
        sfRenderWindow_drawRectangleShape(win->rw, as->lvl.rect[i], NULL);
    while (current != NULL) {
        sfRenderWindow_drawCircleShape(win->rw, current->shape, NULL);
        sfRenderWindow_drawRectangleShape(win->rw, current->lifebar, NULL);
        current = current->next;
    }
    while (curr != NULL) {
        color_tow(win, as->scenes[LVL].sh[1], curr);
        sfRenderWindow_drawCircleShape(win->rw, curr->outshape, NULL);
        sfRenderWindow_drawCircleShape(win->rw, curr->shape, NULL);
        curr = curr->next;
    }
    draw_shop(win, win->scenes[LVL].sh);
    sfRenderWindow_drawSprite(win->rw, as->scenes[LVL].daffyduck->sprite_duck,
    NULL);
}

void draw_scene(window *win, assets *as)
{
    int sce = win->scene;

    for (int i = 0; i < as->scenes[sce].nb_but; i++) {
        sfRenderWindow_drawRectangleShape(win->rw,
        as->scenes[sce].but[i].rect, NULL);
    }
    for (int i = 0; i < as->scenes[sce].nb_text; i++)
        sfRenderWindow_drawText(win->rw, as->scenes[sce].text[i].text, NULL);
    if (win->scene == LVL)
        draw_lvl(win, as);
    popup_show(win, as);
}

void ducking(duck *dd)
{
    sfSprite_setTexture(dd->sprite_duck, dd->texture_duck, sfTrue);
    sfSprite_setTextureRect(dd->sprite_duck, dd->rect);
    sfSprite_setPosition(dd->sprite_duck, dd->position);
}

void main_loop(window *win, assets *as)
{
    while (sfRenderWindow_pollEvent(win->rw, &win->ev))
        get_userinput(win, as);
    if (win->scene == LVL) {
        game_loop(as);
        ducking(win->scenes[LVL].daffyduck);
    }
    if ((win->scene == MENU && win->launched == 1) || as->lives <= 0)
        reset_game(win, as);
    draw_scene(win, as);
}
