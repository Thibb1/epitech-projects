/*
** EPITECH PROJECT, 2020
** load_all.c
** File description:
** calls all loading funct
*/

#include "my_rpg.h"

void load_player(player_s *player)
{
    player->texture = sfTexture_createFromFile("assets/game/player.png", NULL);
    player->sprite = sfSprite_create();
    player->view = sfView_create();
    player->pos = (sfVector2f){66 * 64, 26 * 64};
    player->rect = (sfIntRect){0 * 32, 1 * 32, 32, 32};
    player->state = 0;
    player->dir = 0;
    player->released = 0;
    player->clock = sfClock_create();
    player->clock2 = sfClock_create();
    player->clock3 = sfClock_create();
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setOrigin(player->sprite, (sfVector2f){-16, 16});
    sfSprite_setTexture(player->sprite, player->texture, sfFalse);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setScale(player->sprite, (sfVector2f){3, 3});
    sfView_setCenter(player->view, player->pos);
    sfView_setSize(player->view, (sfVector2f){1920 / 1.3, 1080 / 1.3});
}

void load_sfx(sfx_s *sfx)
{
    sfx->clock = sfClock_create();
    sfx->sprite = sfSprite_create();
    sfx->sprite2 = sfSprite_create();
    sfx->texture = sfTexture_createFromFile("./assets/rain.png", NULL);
    sfx->texture2 = sfTexture_createFromFile("./assets/rainfloor.png", NULL);
    sfSprite_setTexture(sfx->sprite, sfx->texture, sfFalse);
    sfSprite_setTexture(sfx->sprite2, sfx->texture2, sfFalse);
    sfSprite_setTextureRect(sfx->sprite2, (sfIntRect){0, 0, 8, 8});
    sfSprite_setScale(sfx->sprite, (sfVector2f){8, 8});
    sfSprite_setScale(sfx->sprite2, (sfVector2f){4, 4});
}

void load_all(my_rpg *rpg)
{
    load_window(&rpg->r);
    load_player(&rpg->player);
    load_map(&rpg->maps);
    load_interface(&rpg->ui);
    load_sfx(&rpg->sfx);
    load_quest_txt(&rpg->quest);
    load_quest2(&rpg->quest);
    rpg->mode = 0;
}
