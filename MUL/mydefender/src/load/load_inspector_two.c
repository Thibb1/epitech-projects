/*
** EPITECH PROJECT, 2021
** load_inspector.c
** File description:
** load_inspector.c
*/

#include "defender.h"

void load_sell_but(shop *sh)
{
    sfColor but_col[2] = {{90, 90, 90, 255}, {70, 70, 70, 255}};
    sfVector2f b[2] = {{1320, 640}, {305, 120}};
    sfVector2f t[2] = {{1470, 660}, {120, 70}};

    for (int i = 0; i < sh[1].nb_but; i++, b[0].x += 345, b[1].x = 165)
        init_button(&sh[1].but[i], but_col, b, NULL);
    for (int i = 4; i < 6; i++, t[0].x += 345)
        init_text(&sh[1].text[i], sfGreen, t, "Upgrade");
    sfText_setColor(sh[1].text[5].text, sfRed);
    sfText_setString(sh[1].text[5].text, "Sell");
}