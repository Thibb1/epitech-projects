/*
** EPITECH PROJECT, 2020
** match
** File description:
** matches str str
*/

int match(char const *s1, char const *s2)
{
    int rec_val;

    if (s2[0] == '*') {
        if (s1[0])
            rec_val = match(s1, &s2[1]) || match(&s1[1], s2);
        else if (!(s1[0]))
            rec_val = match(s1, &s2[1]);
        return (rec_val);
    }
    else if (s1[0] == s2[0] && s1[0]) {
        rec_val = match(&s1[1], &s2[1]);
        return (rec_val);
    }
    if (!(s1[0]) && !(s2[0]))
        return (1);
    return (0);
}
