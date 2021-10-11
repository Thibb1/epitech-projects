/*
** EPITECH PROJECT, 2021
** menu_ui_event.c
** File description:
** menu_ui_event.c
*/

#include "my_rpg.h"

void menu_click_press(interface_s *ui, sfRenderWindow *window, my_rpg *rpg)
{
    if (ui->menu.play.state == HOVER) {
        sfSound_play(ui->audio.click);
        sfMusic_stop(ui->audio.menu_sic);
        sfMusic_play(ui->audio.game_sic);
        rpg->mode = 1;
        ui->disp_menu = sfFalse;
    }
    if (ui->menu.how_to_play.state == HOVER) {
        sfSound_play(ui->audio.click);
        ui->menu.disp_htp = sfTrue;
    }
    if (ui->menu.quit.state == HOVER) {
        sfSound_play(ui->audio.click);
        sfMusic_stop(ui->audio.menu_sic);
        sfRenderWindow_close(window);
    }
}

void htp_click(interface_s *ui)
{
    if (ui->menu.disp_htp == sfTrue && ui->menu.htp.back.state == HOVER) {
        sfSound_play(ui->audio.click);
        ui->menu.disp_htp = sfFalse;
    }
}

void menu_ui_event(my_rpg *rpg, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (rpg->ui.menu.disp_htp == sfFalse)
            menu_click_press(&rpg->ui, rpg->r.w, rpg);
        else
            htp_click(&rpg->ui);
    }
}