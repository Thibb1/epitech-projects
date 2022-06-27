/*
** EPITECH PROJECT, 2020
** render_sprite.c
** File description:
** game sprite show
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

void render_sprite(sfRenderWindow *ren, objects *ob, game_data *game,
    obstacle *o)
{
    for (int i = BG_NB - 1; i >= 0; i--)
        sfRenderWindow_drawSprite(ren, ob->bg[i].sprite, NULL);
    sfRenderWindow_drawSprite(ren, ob->player.sprite, NULL);
    for (int i = o->ob_left; i < game->ob_nb; i++)
        sfRenderWindow_drawSprite(ren, o->o[i].sprite, NULL);
}