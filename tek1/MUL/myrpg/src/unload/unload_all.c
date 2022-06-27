/*
** EPITECH PROJECT, 2020
** unload_all.c
** File description:
** calls all unloading funct
*/

#include "my_rpg.h"

void unload_player(player_s player)
{
    sfClock_destroy(player.clock);
    sfClock_destroy(player.clock2);
    sfClock_destroy(player.clock3);
    sfView_destroy(player.view);
    sfSprite_destroy(player.sprite);
    sfTexture_destroy(player.texture);
}

void unload_quest(quest_s quest)
{
    sfClock_destroy(quest.clock);
    sfSprite_destroy(quest.sprite);
    sfTexture_destroy(quest.texture);
    sfRectangleShape_destroy(quest.textbox);
    sfFont_destroy(quest.font);
    sfText_destroy(quest.text1);
    sfText_destroy(quest.text2);
    sfText_destroy(quest.text3);
}

void unload_sfx(sfx_s sfx)
{
    sfClock_destroy(sfx.clock);
    sfSprite_destroy(sfx.sprite);
    sfSprite_destroy(sfx.sprite2);
    sfTexture_destroy(sfx.texture);
    sfTexture_destroy(sfx.texture2);
}

void unload_all(my_rpg rpg)
{
    unload_map(rpg.maps);
    unload_window(rpg.r);
    unload_ui(rpg.ui);
    unload_sfx(rpg.sfx);
    unload_player(rpg.player);
    unload_quest(rpg.quest);
}