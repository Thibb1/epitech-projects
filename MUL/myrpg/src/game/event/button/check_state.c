/*
** EPITECH PROJECT, 2021
** check_state.c
** File description:
** check_state.c
*/

#include "my_rpg.h"

int is_hover(sfVector2i cursor, sfFloatRect bounds)
{
    if (cursor.x >= bounds.left && cursor.x <= bounds.left + bounds.width &&
    cursor.y >= bounds.top && cursor.y <= bounds.top + bounds.height)
        return (1);
    return (0);
}

void check_specific_button(sfVector2i cursor, button_s *but,
sfFloatRect bounds)
{
    if (is_hover(cursor, bounds) == 1) {
        but->state = HOVER;
        sfText_setColor(but->text, but->hover);
    } else {
        but->state = IDLE;
        sfText_setColor(but->text, but->idle);
    }
}

void check_menu_button_state(sfVector2i cursor, menu_ui *menu)
{
    sfFloatRect play_b = sfText_getGlobalBounds(menu->play.text);
    sfFloatRect htp_b = sfText_getGlobalBounds(menu->how_to_play.text);
    sfFloatRect quit_b = sfText_getGlobalBounds(menu->quit.text);
    sfFloatRect htp_bck_b = sfText_getGlobalBounds(menu->htp.back.text);

    if (menu->disp_htp == sfFalse) {
        check_specific_button(cursor, &menu->play, play_b);
        check_specific_button(cursor, &menu->how_to_play, htp_b);
        check_specific_button(cursor, &menu->quit, quit_b);
    } else
        check_specific_button(cursor, &menu->htp.back, htp_bck_b);
}

void check_game_ui_buttons(sfVector2i cursor, game_ui *game)
{
    sfFloatRect sound_bounds = sfText_getGlobalBounds(game->sound.text);
    sfFloatRect resume_bounds = sfText_getGlobalBounds(game->resume.text);
    sfFloatRect menu_bounds = sfText_getGlobalBounds(game->menu.text);
    sfFloatRect quit_bounds = sfText_getGlobalBounds(game->quit.text);

    check_specific_button(cursor, &game->sound, sound_bounds);
    check_specific_button(cursor, &game->resume, resume_bounds);
    check_specific_button(cursor, &game->menu, menu_bounds);
    check_specific_button(cursor, &game->quit, quit_bounds);
}

void check_fight_state(sfVector2i cursor, fight_ui *ui)
{
    sfFloatRect back_bounds = sfText_getGlobalBounds(ui->back.text);

    check_specific_button(cursor, &ui->back, back_bounds);
}

void check_state(interface_s *ui, sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (ui->disp_menu == sfTrue)
        check_menu_button_state(pos, &ui->menu);
    if (ui->disp_game == sfTrue && ui->game.dis_s_menu == sfFalse)
        check_game_ui_buttons(pos, &ui->game);
    if (ui->game.dis_s_menu == sfTrue)
        check_soundmenu_state(pos, &ui->game.sound_menu);
    if (ui->disp_fight == sfTrue)
        check_fight_state(pos, &ui->fight);
}