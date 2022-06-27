/*
** EPITECH PROJECT, 2020
** load_calls.c
** File description:
** calls game loading
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

int load_ob_sprite(game_data *game, obstacle *o)
{
    for (int i = 0; i < game->ob_nb; i++) {
        o->o[i].texture = o->o[i].state == 2 ?
            sfTexture_createFromFile("assets/block.png", NULL) :
            sfTexture_createFromFile("assets/enemy.png", NULL);
        o->o[i].sprite = sfSprite_create();
        sfSprite_setTexture(o->o[i].sprite, o->o[i].texture, sfTrue);
        sfSprite_setPosition(o->o[i].sprite, o->o[i].position);
        if (!o->o[i].sprite || !o->o[i].texture)
            return (ERROR);
    }
    return (SUCCESS);
}

int load_obstacles(game_data *game, char *path, obstacle *o)
{
    int file = my_fopen(path, 'r');

    game->ob_nb = 0;
    o->ob_left = 0;
    my_fscanf(file, "%d", &game->ob_nb);
    o->o = malloc(sizeof(object) * game->ob_nb);
    for (int i = 0; i < game->ob_nb; i++) {
        o->o[i].position.x = 0;
        o->o[i].position.y = 0;
        o->o[i].state = 0;
        my_fscanf(file, "%f %f %s", &o->o[i].position.x,
            &o->o[i].position.y, &o->o[i].state);
    }
    my_fclose(file);
    if (load_ob_sprite(game, o))
        return (ERROR);
    return (SUCCESS);
}

int load_calls(game_data *game, game_window *window, char *path, obstacle *o)
{
    if (load_audio(&game->ob) || load_sprites(&game->ob) || load_text(&game->ob)
        || load_window(game, window) || load_clock(game)
        || load_obstacles(game, path, o))
        return (ERROR);
    return (SUCCESS);
}