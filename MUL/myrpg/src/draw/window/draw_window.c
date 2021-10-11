/*
** EPITECH PROJECT, 2020
** draw_window.c
** File description:
** draws all the scene
*/

#include "my_rpg.h"

void draw_quest(my_rpg *rpg, int state)
{
    if (state == 0)
        sfClock_restart(rpg->quest.clock);
    if (state == 1 || state == 2 || state == 4)
        sfRenderWindow_drawRectangleShape(rpg->r.w, rpg->quest.textbox, NULL);
    if (state == 1) {
        sfRenderWindow_drawText(rpg->r.w, rpg->quest.text1, NULL);
        if (sfTime_asSeconds(sfClock_getElapsedTime(rpg->quest.clock)) > 2)
            state = 2;
    }
    if (state == 2) {
        sfRenderWindow_drawText(rpg->r.w, rpg->quest.text1, NULL);
        sfRenderWindow_drawText(rpg->r.w, rpg->quest.text2, NULL);
    }
    if (state == 4)
        sfRenderWindow_drawText(rpg->r.w, rpg->quest.text3, NULL);
}

void draw_window(render r, my_rpg *rpg)
{
    sfRenderTexture_display(r.t);
    sfRenderWindow_drawSprite(r.w, r.t_sprite, NULL);
    sfRenderTexture_clear(r.t, sfBlack);
    draw_quest(rpg, rpg->quest.state);
    draw_ui(rpg->r.w, rpg->ui);
    sfRenderWindow_display(r.w);
    sfRenderWindow_clear(r.w, sfBlack);
}