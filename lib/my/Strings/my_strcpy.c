/*
** EPITECH PROJECT, 2020
** my lib
** File description:
** my strcpy
*/

#include <stddef.h>

size_t my_strlen(char const *str);
size_t my_wstrlen(wchar_t const *str);

void my_strncpy(char *dest, char const *src, size_t n)
{
    size_t i = 0;

    if (dest == NULL || src == NULL)
        return;
    while (src[i] != 0 && i < n){
        dest[i] = src[i];
        i++;
    }
    while (i < n){
        dest[i] = 0;
        i++;
    }
}

void my_strcpy(char *dest, char const *src)
{
    my_strncpy(dest, src, my_strlen(src));
}

void my_wstrncpy(wchar_t *dest, wchar_t const *src, size_t n)
{
    size_t i = 0;

    if (dest == NULL || src == NULL)
        return;
    while (src[i] != 0 && i < n){
        dest[i] = src[i];
        i++;
    }
    while (i < n){
        dest[i] = 0;
        i++;
    }
}

void my_wstrcpy(wchar_t *dest, wchar_t const *src)
{
    my_wstrncpy(dest, src, my_wstrlen(src));
}