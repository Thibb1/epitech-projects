/*
** EPITECH PROJECT, 2021
** game_ui_event.c
** File description:
** game_ui_event.c
*/

#include "my_rpg.h"

void reset_pos_rpg(my_rpg *rpg)
{
    rpg->mode = 0;
    rpg->player.pos.x = 66 * 64;
    rpg->player.pos.y = 26 * 64;
    sfSprite_setPosition(rpg->player.sprite, rpg->player.pos);
    rpg->player.rect.top = 1 * 32;
    sfSprite_setTextureRect(rpg->player.sprite, rpg->player.rect);
    sfView_setCenter(rpg->player.view, rpg->player.pos);
    rpg->quest.state = 0;
}

void gameui_click(interface_s *ui, sfRenderWindow *window, my_rpg *rpg)
{
    if (ui->game.sound.state == HOVER && ui->disp_game == sfTrue) {
        sfSound_play(ui->audio.click);
        ui->game.dis_s_menu = sfTrue;
    } else if (ui->game.resume.state == HOVER && ui->disp_game == sfTrue) {
        sfSound_play(ui->audio.click);
        ui->disp_game = sfFalse;
        rpg->mode = 1;
        sfText_setColor(ui->game.resume.text, sfWhite);
    }
    if (ui->game.menu.state == HOVER && ui->disp_game == sfTrue) {
        sfMusic_stop(ui->audio.game_sic);
        sfSound_play(ui->audio.click);
        sfMusic_play(ui->audio.menu_sic);
        ui->disp_game = sfFalse;
        ui->disp_menu = sfTrue;
        reset_pos_rpg(rpg);
    } else if (ui->game.quit.state == HOVER && ui->disp_game == sfTrue) {
        sfSound_play(ui->audio.click);
        sfMusic_stop(ui->audio.menu_sic);
        sfRenderWindow_close(window);
    }
}

void click_menu(my_rpg *rpg, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (rpg->ui.game.dis_s_menu == sfFalse) {
            gameui_click(&rpg->ui, rpg->r.w, rpg);
        } else
            sound_menu_click(&rpg->ui);
    }
}

void game_ui_event(my_rpg *rpg, sfEvent event)
{
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyEscape && rpg->ui.game.dis_s_menu == sfTrue) {
        sfSound_play(rpg->ui.audio.click);
        rpg->ui.game.dis_s_menu = sfFalse;
        return;
    }
    if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyEscape && rpg->ui.disp_game == sfTrue) {
        sfSound_play(rpg->ui.audio.click);
        rpg->ui.disp_game = sfFalse;
        rpg->mode = 1;
        return;
    } else if (event.type == sfEvtKeyPressed &&
    event.key.code == sfKeyEscape && rpg->ui.disp_game == sfFalse) {
        sfSound_play(rpg->ui.audio.click);
        rpg->ui.disp_game = sfTrue;
        rpg->mode = 2;
        rpg->player.released = 1;
        return;
    }
    click_menu(rpg, event);
}
