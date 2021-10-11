/*
** EPITECH PROJECT, 2020
** load_audio.c
** File description:
** audio loading
*/

#include "../../../include/my.h"
#include "../../../include/my_sfml.h"

int load_audio(objects *ob)
{
    ob->player.sound[0] = sfMusic_createFromFile("assets/walk.ogg");
    ob->player.sound[1] = sfMusic_createFromFile("assets/run.ogg");
    sfMusic_setLoop(ob->player.sound[0], sfTrue);
    sfMusic_setLoop(ob->player.sound[1], sfTrue);
    if (ob->player.sound[0] && ob->player.sound[1])
        return (SUCCESS);
    return (ERROR);
}