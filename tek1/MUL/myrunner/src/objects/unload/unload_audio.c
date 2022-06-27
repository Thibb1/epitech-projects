/*
** EPITECH PROJECT, 2020
** unload_audio.c
** File description:
** aduio unloading
*/

#include "../../../include/my.h"
#include "../../../include/my_sfml.h"

void unload_audio(objects ob)
{
    for (int i = 0; i < SOUND_NB; i++)
        sfMusic_destroy(ob.player.sound[i]);
}