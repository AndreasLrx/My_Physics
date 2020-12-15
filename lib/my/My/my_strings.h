/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** my strings fcts
*/

#ifndef MY_LIB_STRINGS_H
#define MY_LIB_STRINGS_H

#include <stddef.h>

size_t my_strlen(char const *str);
size_t my_wstrlen(wchar_t const *str);

int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_wstrcmp(wchar_t const *s1, wchar_t const *s2);
int my_wstrncmp(wchar_t const *s1, wchar_t const *s2, int n);

void my_strnset(char *str, char value, size_t n);
void my_strset(char *str, char value);
void my_wstrnset(wchar_t *str, wchar_t value, size_t n);
void my_wstrset(wchar_t *str, wchar_t value);

char *my_strndup(char const *str, size_t n);
char *my_strdup(char const *str);
char *my_wstrndup(wchar_t const *str, size_t n);
char *my_wstrdup(wchar_t const *str);

void my_strncpy(char *dest, char const *src, size_t n);
void my_strcpy(char *dest, char const *src);
void my_wstrncpy(wchar_t *dest, wchar_t const *src, size_t n);
void my_wstrcpy(wchar_t *dest, wchar_t const *src);

char *my_strncat(char *dest, char const *src, size_t n);
char *my_strcat(char *dest, char const *src);
wchar_t *my_wstrncat(wchar_t *dest, wchar_t const *src, size_t n);
wchar_t *my_wstrcat(wchar_t *dest, wchar_t const *src);

wchar_t *my_wstrdup_except(wchar_t const *src, wchar_t except);

#endif /* !MY_LIB_STRINGS_H */