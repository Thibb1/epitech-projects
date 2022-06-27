/*
** EPITECH PROJECT, 2020
** my_connect_utils.c
** File description:
** connection utils to communicate between process
*/

#include "../include/my.h"
#include "../include/navy.h"

static int p2 = 0;

void sig_user2(int signal, siginfo_t *siginfo, void *data)
{
    p2 = siginfo->si_pid;
}

void connect_process(net *pids)
{
    struct sigaction signal;

    my_printf("my_pid: %d\n", getpid());
    if (pids->pone) {
        signal.sa_sigaction = &sig_user2;
        signal.sa_flags = SA_SIGINFO;
        sigaction(SIGUSR1, &signal, NULL);
        my_printf("waiting for ennemy connection...");
        pause();
        pids->p2 = p2;
        my_printf("\n\nenemy connected\n\n");
    } else {
        if (kill(pids->p1, SIGUSR1) == -1)
            my_ferror("Connection failed");
        my_printf("successfully connected\n\n");
    }
}