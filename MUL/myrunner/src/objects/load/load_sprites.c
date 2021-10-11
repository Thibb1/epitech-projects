/*
** EPITECH PROJECT, 2020
** load_sprites.c
** File description:
** sprites loading
*/

#include "../../../include/my.h"
#include "../../../include/my_sfml.h"

int load_texture(objects *ob)
{
    ob->bg[0].texture = sfTexture_createFromFile("assets/bg_1.png", NULL);
    ob->bg[1].texture = sfTexture_createFromFile("assets/bg_2.png", NULL);
    ob->bg[2].texture = sfTexture_createFromFile("assets/bg_3.png", NULL);
    ob->player.texture = sfTexture_createFromFile("assets/player.png", NULL);
    if (ob->bg[0].texture && ob->bg[1].texture && ob->bg[2].texture &&
        ob->player.texture)
        return (SUCCESS);
    return (ERROR);
}

static void scaling(objects *ob)
{
    sfFloatRect sprite;
    sfIntRect rect = {0, 0, 1920*2, 1080};
    sfVector2f sprite_scale;

    for (int i = 0; i < BG_NB; i++) {
        sprite = sfSprite_getLocalBounds(ob->bg[i].sprite);
        sprite_scale.x = 1920.f / sprite.width;
        sprite_scale.y = 1080.f / sprite.height;
        sfSprite_scale(ob->bg[i].sprite, sprite_scale);
    }
    for (int i = 0; i < 2; i++) {
        sfTexture_setRepeated(ob->bg[i].texture, sfTrue);
        sfSprite_setTextureRect(ob->bg[i].sprite, rect);
    }
}

int load_sprite(objects *ob)
{
    sfIntRect player = {0, 32, 32, 32};
    sfVector2f scale = {4, 4};

    for (int i = 0; i < 3; i++) {
        ob->bg[i].sprite = sfSprite_create();
        sfSprite_setTexture(ob->bg[i].sprite, ob->bg[i].texture, sfTrue);
    }
    scaling(ob);
    ob->player.sprite = sfSprite_create();
    sfSprite_setTexture(ob->player.sprite, ob->player.texture, sfTrue);
    sfSprite_setTextureRect(ob->player.sprite, player);
    sfSprite_scale(ob->player.sprite, scale);
    if (ob->bg[0].sprite && ob->bg[1].sprite && ob->bg[2].sprite &&
        ob->player.sprite)
        return (SUCCESS);
    return (ERROR);
}

int load_sprites(objects *ob)
{
    if (load_texture(ob) || load_sprite(ob))
        return (ERROR);
    set_poss(&ob->player.position, ob->player.sprite, 100, 780);
    ob->player.current_sprite = 0;
    ob->player.state = WALK;
    ob->player.grounded = 1;
    return (SUCCESS);
}