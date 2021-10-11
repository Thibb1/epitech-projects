/*
** EPITECH PROJECT, 2020
** load_assets.c
** File description:
** load basic assets
*/

#include "defender.h"

void load_colors(assets *as)
{
    sfColor grey = {176, 176, 176, 255};
    sfColor t_white = {255, 255, 255, 224};
    sfColor primary = {90, 90, 90, 255};
    sfColor accent = {70, 70, 70, 255};

    as->disable = grey;
    as->hover = t_white;
    as->primary = primary;
    as->accent = accent;
    as->head = NULL;
    as->t_head = NULL;
}

void load_menu_scene(assets *as, scene *sc)
{
    sfColor colors[2] = {as->primary, as->accent};
    sfColor text_color = {255, 0, 255, 255};
    sfVector2f pos_size[2] = {{560, 410}, {800, 200}};
    sfVector2f def[2] = {{960, 130}, {300, 1}};
    sfVector2f play_quit[2] = {{960, 450}, {200, 0}};

    sc->nb_text = 3;
    sc->nb_but = 2;
    sc->but = (button*) malloc(sc->nb_but * sizeof(button));
    sc->text = (text*) malloc(sc->nb_text * sizeof(text));
    sc->sh = NULL;
    init_text(&sc->text[0], text_color, def, "My Defender");
    init_text(&sc->text[1], text_color, play_quit, "Play");
    init_button(&sc->but[0], colors, pos_size, NULL);
    play_quit[0].y += 300;
    pos_size[0].y += 300;
    init_text(&sc->text[2], text_color, play_quit, "Quit");
    init_button(&sc->but[1], colors, pos_size, NULL);
}

void load_game_scene(scene *sc)
{
    sc->nb_but = 0;
    sc->nb_text = 0;
    sc->text = (text *) malloc(sc->nb_text * sizeof(text));
    sc->but = malloc(sc->nb_but * sizeof(button));
    sc->sh = malloc(sizeof(shop) * 2);
    sc->daffyduck = malloc(sizeof(duck));
    load_inspector(sc->sh);
    create_duck(sc->daffyduck);
}

void load_pause_scene(assets *as, scene *sc)
{
    sfColor colors[2] = {as->primary, as->accent};
    sfVector2f pos_size[2] = {{560, 350}, {800, 200}};
    sfColor text_color = {255, 0, 255, 255};
    sfVector2f pause[2] = {{960, 60}, {300, 1}};
    sfVector2f but_text[2] = {{960, 390}, {200, 0}};

    sc->nb_text = 4;
    sc->nb_but = 3;
    sc->but = (button *) malloc(sizeof(button) * sc->nb_but);
    sc->text = malloc(sizeof(text) * sc->nb_text);
    sc->sh = NULL;
    for (int i = 0; i < 3; i++, pos_size[0].y += 250)
        init_button(&sc->but[i], colors, pos_size, NULL);
    init_text(&sc->text[0], text_color, pause, "Pause");
    init_text(&sc->text[1], text_color, but_text, "Resume");
    but_text[0].y += 250;
    init_text(&sc->text[2], text_color, but_text, "Menu");
    but_text[0].y += 250;
    init_text(&sc->text[3], text_color, but_text, "Quit");
}

void load_assets(assets *as)
{
    load_colors(as);
    as->scenes = (scene *) malloc(sizeof(scene) * (NB_SCENE + 1));
    load_menu_scene(as, &as->scenes[0]);
    load_game_scene(&as->scenes[1]);
    load_pause_scene(as, &as->scenes[2]);
    load_lvl(&as->lvl);
    as->timer = sfClock_create();
    as->s = sfClock_create();
    as->current_s = 0;
    as->coins = START_GOLD;
    as->lives = 5;
    as->font = sfFont_createFromFile("assets/ostrich-regular.ttf");
}