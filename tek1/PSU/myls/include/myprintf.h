/*
** EPITECH PROJECT, 2020
** myprintf.h
** File description:
** myprintf
*/
#ifndef BSPRINTF
#define BSPRINTF
#define MAX_ARGS 31
#include <stdarg.h>
typedef struct flag_s {
    char f;
    char spe;
    int s;
    int h;
    int p;
    int m;
    int dot;
    long wide;
    long precision;
} flag;

int flag_process(va_list li, flag *flag, char a);
int flag_reset(flag *flag);
int flag_parse(const char *str, flag *flag, int count);
void init_pfa(void);
int hex_process(flag *flag, int nb_size, int count);
int base_finder(const char c);
int b_put(const unsigned int nb, const char c, int count);
int c_process(va_list li, flag *flag, int count);
int d_process(va_list li, flag *flag, int count);
int b_process(va_list li, flag *flag, int count);
int p_process(va_list li, flag *flag, int count);
int s_process(va_list li, flag *flag, int count);
#endif
