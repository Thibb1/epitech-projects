/*
** EPITECH PROJECT, 2020
** my_printf.h
** File description:
** my_printf
*/
#ifndef MY_PRINTF
#define MY_PRINTF
#define MAX_ARGS 31

#include "my.h"

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

int flag_process(int fd, va_list li, flag *flag, char a);
int flag_reset(flag *flag);
int flag_parse(const char *str, flag *flag, int count);
void init_pfa(void);
int c_process(int fd, va_list li, flag *flag, int count);
int d_process(int fd, va_list li, flag *flag, int count);
int s_process(int fd, va_list li, flag *flag, int count);
int f_process(int fd, va_list li, flag *flag, int count);

int my_putchar(int fd, int c);
int my_putnbr(int fd, int nb);
int my_putstr(int fd, char const *str);
int my_putnstr(int fd, char const *str, int nb);
#endif
