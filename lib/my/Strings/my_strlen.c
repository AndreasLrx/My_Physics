/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** my strlen
*/

#include <stddef.h>

size_t my_strlen(char const *str)
{
    size_t len = 0;

    if (str == NULL)
        return 0;
    while (str[len] != 0)
        len++;
    return len;
}

size_t my_wstrlen(wchar_t const *wstr)
{
    size_t len = 0;

    if (wstr == NULL)
        return 0;
    while (wstr[len] != 0)
        len++;
    return len;
}