/*
** EPITECH PROJECT, 2021
** check_soundmenu_state.c
** File description:
** check_soundmenu_state.c
*/

#include "my_rpg.h"

void check_soundmenu_state(sfVector2i cursor, s_menu *menu)
{
    sfFloatRect min_mus = sfText_getGlobalBounds(menu->minus_music.text);
    sfFloatRect pl_mus = sfText_getGlobalBounds(menu->plus_music.text);
    sfFloatRect min_eff = sfText_getGlobalBounds(menu->minus_effects.text);
    sfFloatRect pl_eff = sfText_getGlobalBounds(menu->plus_effects.text);
    sfFloatRect back_b = sfText_getGlobalBounds(menu->back.text);

    check_specific_button(cursor, &menu->minus_music, min_mus);
    check_specific_button(cursor, &menu->plus_music, pl_mus);
    check_specific_button(cursor, &menu->minus_effects, min_eff);
    check_specific_button(cursor, &menu->plus_effects, pl_eff);
    check_specific_button(cursor, &menu->back, back_b);
}