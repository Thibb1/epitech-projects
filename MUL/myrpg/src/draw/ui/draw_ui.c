/*
** EPITECH PROJECT, 2021
** draw_ui.c
** File description:
** draw_ui.c
*/

#include "my_rpg.h"

void draw_menu(sfRenderWindow *win, menu_ui menu)
{
    sfRenderWindow_drawText(win, menu.title, NULL);
    if (menu.disp_htp == sfFalse) {
        sfRenderWindow_drawText(win, menu.play.text, NULL);
        sfRenderWindow_drawText(win, menu.how_to_play.text, NULL);
        sfRenderWindow_drawText(win, menu.quit.text, NULL);
    } else {
        sfRenderWindow_drawRectangleShape(win, menu.htp.bg, NULL);
        sfRenderWindow_drawText(win, menu.htp.move, NULL);
        sfRenderWindow_drawText(win, menu.htp.op_menu, NULL);
        sfRenderWindow_drawText(win, menu.htp.navigate, NULL);
        sfRenderWindow_drawText(win, menu.htp.skip, NULL);
        sfRenderWindow_drawText(win, menu.htp.back.text, NULL);
    }
}

void draw_sound_menu(sfRenderWindow *win, game_ui game, interface_s ui)
{
    sfRenderWindow_drawRectangleShape(win, game.sound_menu.bg_shape, NULL);
    sfRenderWindow_drawText(win, game.sound_menu.music, NULL);
    sfRenderWindow_drawText(win, game.sound_menu.effects, NULL);
    sfRenderWindow_drawText(win, game.sound_menu.mus_vol, NULL);
    sfRenderWindow_drawText(win, game.sound_menu.eff_vol, NULL);
    if (ui.audio.music_volume > 0)
        sfRenderWindow_drawText(win, game.sound_menu.minus_music.text, NULL);
    if (ui.audio.music_volume < 100)
        sfRenderWindow_drawText(win, game.sound_menu.plus_music.text, NULL);
    if (ui.audio.sound_volume > 0)
        sfRenderWindow_drawText(win, game.sound_menu.minus_effects.text, NULL);
    if (ui.audio.sound_volume < 100)
        sfRenderWindow_drawText(win, game.sound_menu.plus_effects.text, NULL);
    sfRenderWindow_drawText(win, game.sound_menu.back.text, NULL);
}

void draw_game(sfRenderWindow *win, game_ui game, interface_s ui)
{
    sfRenderWindow_drawRectangleShape(win, game.backg.shape, NULL);
    sfRenderWindow_drawText(win, game.sound.text, NULL);
    sfRenderWindow_drawText(win, game.resume.text, NULL);
    sfRenderWindow_drawText(win, game.menu.text, NULL);
    sfRenderWindow_drawText(win, game.quit.text, NULL);
    if (game.dis_s_menu == sfTrue)
        draw_sound_menu(win, game, ui);
}

void draw_fight(sfRenderWindow *win, fight_ui fight)
{
    sfRenderWindow_drawRectangleShape(win, fight.bg, NULL);
    sfRenderWindow_drawText(win, fight.text, NULL);
    sfRenderWindow_drawText(win, fight.back.text, NULL);
}

void draw_ui(sfRenderWindow *win, interface_s ui)
{
    if (ui.disp_menu == sfTrue)
        draw_menu(win, ui.menu);
    if (ui.disp_game == sfTrue)
        draw_game(win, ui.game, ui);
    if (ui.disp_fight == sfTrue)
        draw_fight(win, ui.fight);
}
