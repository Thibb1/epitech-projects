/*
** EPITECH PROJECT, 2020
** mynmatch
** File description:
** mynmatch
*/

#include <stdlib.h>

int nmatch(char const *s1, char const *s2)
{
    int rec_val;

    if (s2[0] == '*') {
        if (s1[0])
            rec_val = nmatch(s1, &s2[1]) + nmatch(&s1[1], s2);
        else if (!(s1[0]))
            rec_val = nmatch(s1, &s2[1]);
        return (rec_val);
    }
    else if (s1[0] && s1[0] == s2[0]) {
        rec_val = nmatch(&s1[1], &s2[1]);
        return (rec_val);
    }
    if (!(s1[0]) && !(s2[0]))
        return (1);
    return (0);
}
