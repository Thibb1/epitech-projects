/*
** EPITECH PROJECT, 2021
** load_interface.c
** File description:
** load_interface.c
*/

#include "my_rpg.h"

void load_audio(audio_s *s)
{
    s->click_sbuf = sfSoundBuffer_createFromFile("./assets/buttons_click.ogg");
    s->click = sfSound_create();
    sfSound_setBuffer(s->click, s->click_sbuf);
    s->menu_sic = sfMusic_createFromFile("./assets/menu/menu_music.ogg");
    s->game_sic = sfMusic_createFromFile("./assets/game/game_music.ogg");
    sfMusic_setLoop(s->menu_sic, sfTrue);
    sfMusic_setLoop(s->game_sic, sfTrue);
    sfMusic_play(s->menu_sic);
    s->music_volume = 50;
    s->sound_volume = 50;
    s->mus_vol = my_itoa(5);
    s->s_vol = my_itoa(5);
    sfMusic_setVolume(s->menu_sic, 50);
    sfMusic_setVolume(s->game_sic, 50);
    sfSound_setVolume(s->click, 50);
}

void load_interface(interface_s *ui)
{
    load_audio(&ui->audio);
    load_menu_interface(&ui->menu);
    load_game_interface(&ui->game);
    load_fight_interface(&ui->fight);
    ui->disp_menu = sfTrue;
    ui->disp_game = sfFalse;
    ui->disp_fight = sfFalse;
}