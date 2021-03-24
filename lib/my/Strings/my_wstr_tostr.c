/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** wide strings to normal strings
*/

#include <stddef.h>
#include <stdlib.h>

size_t my_wstrlen(wchar_t const *wstr);

char *my_wstr_tostr(wchar_t *wstr)
{
    size_t len = my_wstrlen(wstr);
    char *str = malloc(sizeof(char) * (len + 1));

    for (size_t i = 0; i < len; i++)
        str[i] = (char)wstr[i];
    str[len] = 0;
    return str;
}