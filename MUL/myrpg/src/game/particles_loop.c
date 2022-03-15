/*
** EPITECH PROJECT, 2020
** particles_loop.c
** File description:
** loop for particles
*/

#include "my_rpg.h"

void draw_particles(sfx_s *sfx, sfRenderTexture *t)
{
    sfIntRect rect = {0, 0, 8, 8};
    if (sfTime_asSeconds(sfClock_getElapsedTime(sfx->clock)) > 0.2) {
        for (int i = 0; i < 20; i++) {
            sfx->pos[i].x = RAND(30 * 64, 0);
            sfx->pos[i].y = RAND(38 * 64, 6 * 64);
            rect.left = RAND_INT(0, 2) * 8;
            sfSprite_setTextureRect(sfx->sprite, rect);
            sfSprite_setTextureRect(sfx->sprite2, rect);
            sfx->pos2[i].x = RAND(30 * 64, 0);
            sfx->pos2[i].y = RAND(38 * 64, 6 * 64);
        }
        sfClock_restart(sfx->clock);
    }
    for (int i = 0; i < 20; i++) {
        sfSprite_setPosition(sfx->sprite, sfx->pos[i]);
        sfSprite_setPosition(sfx->sprite2, sfx->pos2[i]);
        sfRenderTexture_drawSprite(t, sfx->sprite, NULL);
        sfRenderTexture_drawSprite(t, sfx->sprite2, NULL);
    }
}
