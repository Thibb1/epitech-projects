/*
** EPITECH PROJECT, 2020
** load_map.c
** File description:
** navy game load map
*/

#include "../include/my.h"
#include "../include/navy.h"

int check_boats(char b[32])
{
    if (b[5] - b[2] != 1 && b[6] - b[3] != 1)
        return (my_ferror("Boat 2 wrong size"));
    if (b[13] - b[10] != 2 && b[14] - b[11] != 2)
        return (my_ferror("Boat 2 wrong size"));
    if (b[21] - b[18] != 3 && b[22] - b[19] != 3)
        return (my_ferror("Boat 2 wrong size"));
    if (b[29] - b[26] != 4 && b[30] - b[27] != 4)
        return (my_ferror("Boat 2 wrong size"));
    return (0);
}

int load_boats(char map[2][8][8], char buff[32])
{
    for (int i = buff[10] - 'A'; i <= buff[13] - 'A'; i++)
        for (int b = buff[11] - '1'; b <= buff[14] - '1'; b++)
            map[0][i][b] = '3';
    for (int i = buff[18] - 'A'; i <= buff[21] - 'A'; i++)
        for (int b = buff[19] - '1'; b <= buff[22] - '1'; b++)
            map[0][i][b] = '4';
    for (int i = buff[26] - 'A'; i <= buff[29] - 'A'; i++)
        for (int b = buff[27] - '1'; b <= buff[30] - '1'; b++)
            map[0][i][b] = '5';
    return (check_boats(buff));
}

int load_map(char *path, char map[2][8][8])
{
    char buff[32] = {0};
    int file = my_fopen(path, 'r');

    read(file, buff, 32);
    my_fclose(file);
    if (check_file(buff) == 84)
        return (84);
    for (int i = 0; i < 8; i++)
        for (int b = 0; b < 8; b++) {
            map[0][i][b] = '.';
            map[1][i][b] = '.';
        }
    map[0][buff[2] - 'A'][buff[3] - '1'] = '2';
    map[0][buff[5] - 'A'][buff[6] - '1'] = '2';
    return (load_boats(map, buff));
}
