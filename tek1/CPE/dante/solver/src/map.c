/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** map utilities
*/

#include "solver.h"

char *get_map(char *path)
{
    FILE *f = fopen(path, "r");
    long size;
    char *buffer = NULL;

    if (f == NULL) {
        my_ferror("./solver: can't open file.");
        return (NULL);
    }
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (m_check(buffer = malloc(size + 1)))
        return (NULL);
    fread(buffer, 1, size, f);
    fclose(f);
    buffer[size] = 0;
    return (buffer);
}

int line_map(map_s *m, char *buffer, int y)
{
    int pos;
    int x = 0;

    if (m_check(m->map[y] = malloc(sizeof(int) * m->len)))
        return (FAILURE);
    if (m_check(m->pmap[y] = malloc(sizeof(int) * m->len)))
        return (FAILURE);
    for (; x < m->len; x++) {
        pos = y * (m->len + 1) + x;
        if (!my_grep("*X", buffer[pos]))
            return (my_ferror("./solver: wrong map."));
        m->map[y][x] = buffer[pos] == '*' ? 0 : 1;
        m->pmap[y][x] = -1;
    }
    return (SUCCESS);
}

int parse_map(map_s *m, char *buffer)
{
    for (; buffer[m->len] && buffer[m->len] != '\n'; m->len++);
    for (int x = m->len; buffer[x]; x++)
        m->height += buffer[x] == '\n' ? 1 : 0;
    if (m_check(m->map = malloc(sizeof(int *) * m->height)))
        return (FAILURE);
    if (m_check(m->pmap = malloc(sizeof(int *) * m->height)))
        return (FAILURE);
    for (int y = 0; y < m->height; y++)
        if (line_map(m, buffer, y))
            return (FAILURE);
    return (SUCCESS);
}

void free_map(map_s *m)
{
    for (int y = 0; y < m->height; y++) {
        free(m->map[y]);
        free(m->pmap[y]);
    }
    free(m->map);
    free(m->pmap);
}