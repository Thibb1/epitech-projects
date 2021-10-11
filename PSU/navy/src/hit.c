/*
** EPITECH PROJECT, 2020
** move2.c
** File description:
** navy game
*/

#include "../include/my.h"
#include "../include/navy.h"

int get_hit(int curent_sig)
{
    struct sigaction s1 = {0};

    s1.sa_sigaction = &send_mode;
    sigaction(SIGUSR1, &s1, NULL);
    sigaction(SIGUSR2, &s1, NULL);
    get_mode(0);
    while ((curent_sig = get_mode(-2)) == 0) {
        usleep(500);
    }
    return (get_mode(-3));
}

void send_hit(int hit, int p2id)
{
    if (hit) {
        usleep(1000);
        kill(p2id, SIGUSR2);
    }
    usleep(1000);
    kill(p2id, SIGUSR1);
}