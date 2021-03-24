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
size_t my_strlen_to(char const *str, char end);
size_t my_wstrlen_to(wchar_t const *str, wchar_t end);

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

int my_get_char_in(char const *str, char c);

char *my_revstr(char *str);

char **my_str_to_tab(char *str, char sep);
char *my_tab_to_str(char **tab, char sep);

char *my_strchr(char const *str, char c);
wchar_t *my_wstrchr(wchar_t const *str, wchar_t c);
char *my_wstr_tostr(wchar_t *wstr);

#endif /* !MY_LIB_STRINGS_H */
