/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** Library prototypes
*/

#ifndef DEF_MAIN
#define DEF_MAIN

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
/// @brief Keyword to return 84 on failure.
#define FAILURE 84

/// @brief Keyword to return 0 on success.
#define SUCCESS 0

#define ABS(x) ((x) < 0 ? (x) * -1 : (x))

#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

/// @brief Returns the square root of a number
/// @param double number to square
double my_sqrt(double nb);

/// @brief Returns the power a number x by a number y
/// @param x [db] number who multiplies by himself
/// @param y [it] number of times he will multiply himself
double my_pow(double x, int y);

/// @brief Returns an integer contained in str
/// @param str string containing integer number
int my_atoi(const char *str);

/// @brief Returns a float contained in str
/// @param str string containing floating point number
double my_atof(const char *str);

/// @brief Returns the length of a int.
/// @param number integer
int my_ilen(const int number);

/// @brief Returns pointer to a string containing the number.
/// @param number integer
char *my_itoa(int number);

/// @brief Returns pointer to a string containing the number.
/// @param number double
/// @param precision number of floating point digits
char *my_ftoa(double number, int precision);

/// @brief Return 84 and print an error message.
/// @param error Error message to print
int my_ferror(const char *error);

/// @brief Write formatted output to stdout.
int my_printf(const char *str, ...);

/// @brief Write formatted output to a file descriptor.
/// @param  fd  file descriptor
/// @param  str format
int my_dprintf(int fd, const char *str, ...);

/// @brief Check the return value of a malloc.
/// @param m_ret Malloc return value
int m_check(void *m_ret);

/// @brief  Return the number of occurrences of a character
///         in a string.
/// @param str  String to check
/// @param c    Character to check
int my_grep(const char *str, const char c);

/// @brief  Return the length of a string.
/// @param str String to calculate
int my_strlen(char const *str);

/// @brief  Compares two strings.
/// @param s1 First string to compare
/// @param s2 Second string to compare
int my_strcmp(char const *s1, char const *s2);

/// @brief  Compares two strings until it reaches n char.
/// @param s1 First string to compare
/// @param s2 Second string to compare
/// @param n  Number of characters to compare
int my_strncmp(char const *s1, char const *s2, int n);

/// @brief  Copies all character of source into dest.
/// @param dest String destination
/// @param src  String source
char *my_strcpy(char *dest, char const *src);

/// @brief  Copies n character of source into dest.
/// @param dest String destination
/// @param src  String source
/// @param n    Number of characters to copy
char *my_strncpy(char *dest, char const *src, int n);

/// @brief  Return a reversed copy of a string.
/// @param src String to reverse
char *my_revstr(char *src);

/// @brief  Import src string into dest string.
/// @param dest String destination
/// @param src  String source
char *my_strcat(char *dest, char const *src);

/// @brief  Import n char of src string into dest string.
/// @param dest String destination
/// @param src  String source
/// @param n    Number of char to import
char *my_strncat(char *dest, char const *src, const int nb);

/// @brief  Return a malloced duplicate a string.
/// @param src String to duplicate
char *my_strdup(const char *str);

#endif