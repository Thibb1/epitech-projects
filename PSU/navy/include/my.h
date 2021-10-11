/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** Library prototypes
*/

#ifndef DEF_MAIN
#define DEF_MAIN

#define ABS(x) ((x < 0) ? (x * -1L) : (x))

#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>

int my_ferror(const char *error);
int my_printf(const char *str, ...);
void m_check(void *m_ret);

int my_putchar(int c);
void my_swap(int *a, int *b);
int my_putnbrbase(unsigned int nbr, char const *base);
int my_putisprintable(char c);
int my_putnisprintable(char c, int nb);
int my_putnbr(int nb);
int my_putstr(char const *str);
int my_putnstr(char const *str, int nb);
int my_showstr(char const *str);
int my_shownstr(char const *str, int nb);

int my_grep(const char *exp, const char src);

char my_is_down_case(char c);
char my_is_up_case(char c);
int my_is_int(long long n, int fn, int nb);
int my_is_prime(int nb);
int my_is_printable(char c);
int my_is_alpha_one(char c);
int my_is_alpha_num(char c);
int my_is_numone(char c);

int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int str_count_words(char const *str);

int my_check_prime(int nb, int i);
int my_find_prime_sup(int nb);

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);

int my_getnbr(char const *str);

int my_intlen(int const *arr);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, const int nb);
char *my_strcapitalize(char *str);
char *my_strlowcase(char *str);
char *my_strupcase(char *str);
char *my_strstr(char *str, char const *to_find);
#endif
