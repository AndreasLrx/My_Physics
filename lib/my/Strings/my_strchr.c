/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** schr lib
*/

#include <stddef.h>

size_t my_strlen(char const *str);
size_t my_wstrlen(wchar_t const *str);

char *my_strchr(char const *str, char c)
{
    size_t len = my_strlen(str);

    for (size_t i = 0; i < len; i++) {
        if (str[i] == c)
            return (char *)str + i;
    }
    return NULL;
}

wchar_t *my_wstrchr(wchar_t const *str, char c)
{
    size_t len = my_wstrlen(str);

    for (size_t i = 0; i < len; i++) {
        if (str[i] == c)
            return (wchar_t *)str + i;
    }
    return NULL;
}