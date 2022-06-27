/*
** EPITECH PROJECT, 2021
** load_sound_menu.c
** File description:
** load_sound_menu.c
*/

#include "my_rpg.h"

void load_sound_menu_texts(s_menu *menu)
{
    menu->music = sfText_create();
    menu->effects = sfText_create();
    sfText_setFont(menu->music, menu->font);
    sfText_setFont(menu->effects, menu->font);
    sfText_setCharacterSize(menu->music, 60);
    sfText_setCharacterSize(menu->effects, 60);
    sfText_setString(menu->music, "Music");
    sfText_setString(menu->effects, "Effects");
    sfText_setColor(menu->music, (sfColor){230, 230, 0, 255});
    sfText_setColor(menu->effects, (sfColor){230, 230, 0, 255});
    sfText_setOutlineThickness(menu->music, 3);
    sfText_setOutlineThickness(menu->effects, 3);
    sfText_setOutlineColor(menu->music, (sfColor){30, 0, 180, 255});
    sfText_setOutlineColor(menu->effects, (sfColor){30, 0, 180, 255});
    sfText_setPosition(menu->music, (sfVector2f){720, 420});
    sfText_setPosition(menu->effects, (sfVector2f){680, 570});
}

void load_sound_menu_vol_text(s_menu *menu)
{
    menu->mus_vol = sfText_create();
    menu->eff_vol = sfText_create();
    sfText_setFont(menu->mus_vol, menu->font);
    sfText_setFont(menu->eff_vol, menu->font);
    sfText_setCharacterSize(menu->mus_vol, 60);
    sfText_setCharacterSize(menu->eff_vol, 60);
    sfText_setString(menu->mus_vol, "5");
    sfText_setString(menu->eff_vol, "5");
    sfText_setColor(menu->mus_vol, (sfColor){230, 230, 0, 255});
    sfText_setColor(menu->eff_vol, (sfColor){230, 230, 0, 255});
    sfText_setOutlineThickness(menu->mus_vol, 3);
    sfText_setOutlineThickness(menu->eff_vol, 3);
    sfText_setOutlineColor(menu->mus_vol, (sfColor){30, 0, 180, 255});
    sfText_setOutlineColor(menu->eff_vol, (sfColor){30, 0, 180, 255});
    sfText_setPosition(menu->mus_vol, (sfVector2f){1080, 420});
    sfText_setPosition(menu->eff_vol, (sfVector2f){1080, 570});
}

void load_sound_menu(s_menu *menu)
{
    menu->bg_shape = sfRectangleShape_create();
    menu->bg_outline = (sfColor){96, 38, 96, 255};
    sfRectangleShape_setFillColor(menu->bg_shape, sfWhite);
    sfRectangleShape_setOutlineThickness(menu->bg_shape, 10);
    sfRectangleShape_setOutlineColor(menu->bg_shape, menu->bg_outline);
    sfRectangleShape_setSize(menu->bg_shape, (sfVector2f){600, 400});
    sfRectangleShape_setPosition(menu->bg_shape, (sfVector2f){(660), (390)});
    menu->font = sfFont_createFromFile("./assets/poke_font/hollow.ttf");
    load_sound_menu_texts(menu);
    load_sound_menu_vol_text(menu);
    load_minus_music(&menu->minus_music);
    load_plus_music(&menu->plus_music);
    load_minus_effects(&menu->minus_effects);
    load_plus_effects(&menu->plus_effects);
    load_back_button(&menu->back);
}