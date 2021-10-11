/*
** EPITECH PROJECT, 2021
** load_sounds.c
** File description:
** load_sounds.c
*/

#include "defender.h"

void init_quit_sounds(sound *s)
{
    s->sound = sfSound_create();
    s->sound_buffer = sfSoundBuffer_createFromFile("assets/quit.ogg");
    sfSound_setBuffer(s->sound, s->sound_buffer);
}