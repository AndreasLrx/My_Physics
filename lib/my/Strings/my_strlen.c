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

size_t my_strlen_to(char const *str, char end)
{
    size_t len = 0;

    if (str == NULL)
        return 0;
    while (str[len] != 0 && str[len] != end)
        len++;
    return len;
}

size_t my_wstrlen_to(wchar_t const *wstr, wchar_t end)
{
    size_t len = 0;

    if (wstr == NULL)
        return 0;
    while (wstr[len] != 0 && wstr[len] != end)
        len++;
    return len;
}