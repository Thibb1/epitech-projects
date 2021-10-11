/*
** EPITECH PROJECT, 2021
** sound_menu_event.c
** File description:
** sound_menu_event.c
*/

#include "my_rpg.h"

void music_volume_click(interface_s *ui)
{
    if (ui->game.sound_menu.minus_music.state == HOVER &&
    ui->audio.music_volume > 0) {
        sfSound_play(ui->audio.click);
        ui->audio.music_volume -= 10;
        free(ui->audio.mus_vol);
        ui->audio.mus_vol = my_itoa(ui->audio.music_volume / 10);
        sfMusic_setVolume(ui->audio.menu_sic, ui->audio.music_volume);
        sfMusic_setVolume(ui->audio.game_sic, ui->audio.music_volume);
        sfText_setString(ui->game.sound_menu.mus_vol, ui->audio.mus_vol);
    }
    if (ui->game.sound_menu.plus_music.state == HOVER &&
    ui->audio.music_volume < 100) {
        sfSound_play(ui->audio.click);
        ui->audio.music_volume += 10;
        free(ui->audio.s_vol);
        ui->audio.s_vol = my_itoa(ui->audio.sound_volume / 10);
        sfMusic_setVolume(ui->audio.menu_sic, ui->audio.music_volume);
        sfMusic_setVolume(ui->audio.game_sic, ui->audio.music_volume);
        sfText_setString(ui->game.sound_menu.mus_vol, ui->audio.mus_vol);
    }
}

void effects_volume_click(interface_s *ui)
{
    if (ui->game.sound_menu.minus_effects.state == HOVER &&
    ui->audio.sound_volume > 0) {
        sfSound_play(ui->audio.click);
        ui->audio.sound_volume -= 10;
        sprintf(ui->audio.s_vol, "%i", ui->audio.sound_volume / 10);
        sfSound_setVolume(ui->audio.click, ui->audio.sound_volume);
        sfText_setString(ui->game.sound_menu.eff_vol, ui->audio.s_vol);
    }
    if (ui->game.sound_menu.plus_effects.state == HOVER &&
    ui->audio.sound_volume < 100) {
        sfSound_play(ui->audio.click);
        ui->audio.sound_volume += 10;
        sprintf(ui->audio.s_vol, "%i", ui->audio.sound_volume / 10);
        sfSound_setVolume(ui->audio.click, ui->audio.sound_volume);
        sfText_setString(ui->game.sound_menu.eff_vol, ui->audio.s_vol);
    }
}

void sound_menu_click(interface_s *ui)
{
    music_volume_click(ui);
    effects_volume_click(ui);
    if (ui->game.sound_menu.back.state == HOVER) {
        sfSound_play(ui->audio.click);
        ui->game.dis_s_menu = sfFalse;
        sfText_setColor(ui->game.sound_menu.back.text, sfWhite);
    }
}