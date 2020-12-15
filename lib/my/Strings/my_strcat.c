/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** Strings - strcat
*/

#include <stddef.h>

size_t my_strlen(char const *str);
size_t my_wstrlen(wchar_t const *str);

char *my_strncat(char *dest, char const *src, size_t n)
{
    while (*dest != 0)
        dest++;
    for (size_t i = 0; i < n; i++) {
        *dest = src[i];
        dest++;
    }
    return dest;
}

char *my_strcat(char *dest, char const *src)
{
    return my_strncat(dest, src, my_strlen(src));
}

wchar_t *my_wstrncat(wchar_t *dest, wchar_t const *src, size_t n)
{
    while (*dest != 0)
        dest++;
    for (size_t i = 0; i < n; i++) {
        *dest = src[i];
        dest++;
    }
    return dest;
}

wchar_t *my_wstrcat(wchar_t *dest, wchar_t const *src)
{
    return my_wstrncat(dest, src, my_wstrlen(src));
}