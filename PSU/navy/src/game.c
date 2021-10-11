/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** navy game
*/

#include "../include/my.h"
#include "../include/navy.h"

void game_p1(net pids, char map[2][8][8], int *win)
{
    char move[4];

    show_map(map);
    send_move(ask_move(move), pids.p2);
    apply_move(map, move, get_hit(0));
    if ((*win = check_win(map)) != 0)
        return;
    get_move(move, 0);
    send_hit(apply_move(map, move, 2), pids.p2);
}

void game_p2(net pids, char map[2][8][8], int *win)
{
    char move[4];

    show_map(map);
    get_move(move, 0);
    send_hit(apply_move(map, move, 2), pids.p1);
    if ((*win = check_win(map)) != 0)
        return;
    send_move(ask_move(move), pids.p1);
    apply_move(map, move, get_hit(0));
}

int game(net pids, char map[2][8][8])
{
    int win = 0;

    while (win == 0)
        if (pids.pone) {
            game_p1(pids, map, &win);
        } else {
            game_p2(pids, map, &win);
        win = check_win(map);
    }
    print_win(win);
    if (win != 1)
        win = 0;
    return (win);
}

