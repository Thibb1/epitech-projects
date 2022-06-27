/*
** EPITECH PROJECT, 2021
** load_inspector.c
** File description:
** load_inspector.c
*/

#include "defender.h"

sfRectangleShape *load_outline(sfRectangleShape *window, sfVector2f win_size,
sfVector2f win_pos)
{
    sfColor out = {70, 70, 70, 255};
    sfColor in = {35, 35, 35, 1};

    window = sfRectangleShape_create();
    sfRectangleShape_setSize(window, win_size);
    sfRectangleShape_setOutlineThickness(window, 5);
    sfRectangleShape_setPosition(window, win_pos);
    sfRectangleShape_setFillColor(window, in);
    sfRectangleShape_setOutlineColor(window, out);
    return (window);
}

void load_towers(shop *sh)
{
    sfVector2f p_main = {1380, 30};
    sfVector2f p_sec = {1405, 55};

    for (int i = 4; i < 8; i++) {
        sh->shapes[i] = sfCircleShape_create();
        sfCircleShape_setFillColor(sh->shapes[i], sfWhite);
        sfCircleShape_setRadius(sh->shapes[i], 25);
    }
    for (int i = 0; i < 4; i++, p_main.y += 150, p_sec.y += 150) {
        sh->shapes[i] = sfCircleShape_create();
        sfCircleShape_setFillColor(sh->shapes[i], sfGreen);
        sfCircleShape_setRadius(sh->shapes[i], 50);
        sfCircleShape_setPosition(sh->shapes[i], p_main);
        sfCircleShape_setPosition(sh->shapes[i + 4], p_sec);
    }
    sfCircleShape_setPointCount(sh->shapes[5], T_TRIANGLE);
    sfCircleShape_setPointCount(sh->shapes[6], T_SQUARE);
    sfCircleShape_setPointCount(sh->shapes[7], T_OCTAGON);
    sfText_setString(sh->text[3].text, "Little Boy");
}

shop load_upper(shop sh)
{
    sfVector2f a_size = {600, 600};
    sfVector2f a_pos = {1315, 5};
    sfColor but_col[2] = {{90, 90, 90, 255}, {70, 70, 70, 255}};
    sfVector2f but_pos_size[2] = {{1500, 20}, {400, 120}};
    sfColor text_col = {255, 0, 255, 255};
    sfVector2f text_pos_size[2] = {{1660, 38}, {120, 70}};

    sh.outline = load_outline(sh.outline, a_size, a_pos);
    sh.nb_text = 4;
    sh.nb_but = 4;
    sh.text = malloc(sh.nb_text * sizeof(text));
    sh.but = malloc(sh.nb_but * sizeof(button));
    for (int i = 0; i < sh.nb_but; but_pos_size[0].y += 150, i++)
        init_button(&sh.but[i], but_col, but_pos_size, NULL);
    for (int i = 0; i < sh.nb_text; text_pos_size[0].y += 150, i++)
        init_text(&sh.text[i], text_col, text_pos_size, "Bratata");
    load_towers(&sh);
    sfText_setString(sh.text[1].text, "Bang Bang");
    sfText_setString(sh.text[2].text, "Big Boum");
    return (sh);
}

shop load_lower(shop sh)
{
    sfVector2f b_size = {600, 465};
    sfVector2f b_pos = {1315, 610};
    sfColor text_col = {255, 0, 255, 255};
    sfVector2f text_pos_size[2] = {{1450, 800}, {120, 70}};

    sh.outline = load_outline(sh.outline, b_size, b_pos);
    sh.nb_text = 6;
    sh.nb_but = 2;
    sh.text = malloc(sh.nb_text * sizeof(text));
    sh.but = malloc(sh.nb_but * sizeof(button));
    for (int i = 0; i < 2; text_pos_size[0].y += 150, i++)
        init_text(&sh.text[i], text_col, text_pos_size, "Golds:");
    text_pos_size[0].x += 200;
    text_pos_size[0].y -= 150;
    for (int i = 2; i < 4; text_pos_size[0].y -= 150, i++)
        init_text(&sh.text[i], text_col, text_pos_size, "0");
    sfText_setString(sh.text[1].text, "Lives:");
    return (sh);
}

void load_inspector(shop *sh)
{
    sh[0] = load_upper(sh[0]);
    sh[1] = load_lower(sh[1]);
    load_sell_but(sh);
}
