/*
** EPITECH PROJECT, 2020
** myheader
** File description:
** my own headers file
*/

#ifndef DEF_MAIN
#define DEF_MAIN
void my_putchar(char c);
void my_swap(int *a, int *b);
void my_putnbr_base(int nbr, char const *base);
int my_put_isprintable(char c);
int my_put_nbr(int nb);

int my_putstr(char const *str);

char my_is_down_case(char c);
char my_is_up_case(char c);
int my_isneg(int n);
int my_is_int(long long n, int fn, int nb);
int my_is_prime(int nb);
int my_is_printable(char c);
int my_is_printable_one(char c);
int my_is_numone(char c);
int my_is_alpha_one(char c);

int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);

int my_find_prime_sup(int nb);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);

int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);

int my_getnbr(char const *str);

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

void my_sort_int_array(int *array, int size);
int my_arrlen(char * const *tab);
#endif
