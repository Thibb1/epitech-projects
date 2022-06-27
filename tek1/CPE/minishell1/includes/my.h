/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** Library prototypes
*/

#ifndef DEF_MAIN
#define DEF_MAIN
#define FAILURE 84
#define SUCCESS 0
#define ABS(x) ((x < 0) ? (x * -1L) : (x))

#include <string.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <stdarg.h>

int my_ferror(const char *error);
int my_printf(const char *str, ...);
void m_check(void *m_ret);

void my_swap(int *a, int *b);

int my_grep(const char *chars_to_search, const char c);

int my_getnbr(char const *str_with_number);
int my_is_int(long long n, int x, int a);

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *src);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, const int nb);
char *my_strcapitalize(char *src);
char *my_strlowcase(char *src);
char *my_strupcase(char *src);
char *my_strstr(char *src, char const *to_find);
#endif
