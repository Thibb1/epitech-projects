/*
** EPITECH PROJECT, 2020
** unload_sprites.c
** File description:
** sprites unloading
*/

#include "../../../include/my.h"
#include "../../../include/my_sfml.h"

void unload_texture(objects ob)
{
    for (int i = 0; i < BG_NB; i++)
        sfTexture_destroy(ob.bg[i].texture);
    sfTexture_destroy(ob.player.texture);
}

void unload_sprite(objects ob)
{
    for (int i = 0; i < BG_NB; i++)
        sfSprite_destroy(ob.bg[i].sprite);
    sfSprite_destroy(ob.player.sprite);
}

void unload_sprites(objects ob)
{
    unload_texture(ob);
    unload_sprite(ob);
}