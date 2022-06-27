/*
** EPITECH PROJECT, 2020
** render_text.c
** File description:
** game text display
*/

#include "../../include/my.h"
#include "../../include/my_sfml.h"

void render_text(sfRenderWindow *ren, objects ob, game_data *game)
{
    if (game->state == MENU) {
        sfRenderWindow_drawText(ren, ob.text[1].text, NULL);
        sfRenderWindow_drawText(ren, ob.text[0].text, NULL);
    }
    sfRenderWindow_drawText(ren, ob.text[3].text, NULL);
    sfRenderWindow_drawText(ren, ob.text[2].text, NULL);
    if (game->state == LOOSE) {
        sfRenderWindow_drawText(ren, ob.text[4].text, NULL);
        sfRenderWindow_drawText(ren, ob.text[6].text, NULL);
    } else if (game->state == WIN) {
        sfRenderWindow_drawText(ren, ob.text[4].text, NULL);
        sfRenderWindow_drawText(ren, ob.text[5].text, NULL);
    }
}