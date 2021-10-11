/*
** EPITECH PROJECT, 2020
** load_text.c
** File description:
** text loading
*/

#include "../../../include/my.h"
#include "../../../include/my_sfml.h"

static void set_string(objects *ob)
{
    sfText_setString(ob->text[0].text, "Death Runner");
    sfText_setString(ob->text[1].text, "Press P to un-pause");
    sfText_setString(ob->text[2].text, "Score : ");
    sfText_setString(ob->text[3].text, "0");
    sfText_setString(ob->text[4].text, "Press Esc key to close the game");
    sfText_setString(ob->text[5].text, "You win !! Well played !");
    sfText_setString(ob->text[6].text, "You loose, try again !");
    sfText_setCharacterSize(ob->text[0].text, 50);
    sfText_setCharacterSize(ob->text[1].text, 30);
    sfText_setCharacterSize(ob->text[2].text, 30);
    sfText_setCharacterSize(ob->text[3].text, 25);
    sfText_setCharacterSize(ob->text[4].text, 30);
    sfText_setCharacterSize(ob->text[5].text, 30);
    sfText_setCharacterSize(ob->text[6].text, 30);
}

static void set_pos(objects *ob)
{
    set_post(ob->text[0].text, 500, 360);
    set_post(ob->text[1].text, 500, 460);
    set_post(ob->text[2].text, 10, 50);
    set_post(ob->text[3].text, 350, 50);
    set_post(ob->text[4].text, 500, 50);
    set_post(ob->text[5].text, 500, 600);
    set_post(ob->text[6].text, 500, 600);
}

int load_text(objects *ob)
{
    ob->font = sfFont_createFromFile("assets/font.ttf");
    for (int i = 0; i < TEXT_NB; i++) {
        ob->text[i].text = sfText_create();
        if (!(ob->text[i].text))
            return (ERROR);
        sfText_setFont(ob->text[i].text, ob->font);
    }
    set_string(ob);
    set_pos(ob);
    if (ob->font)
        return (SUCCESS);
    return (ERROR);
}