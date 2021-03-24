/*
** EPITECH PROJECT, 2020
** My Lib
** File description:
** tests - wchar
*/

#include <stddef.h>

int my_wchar_isnum(wchar_t c)
{
    return (c >= '0' && c <= '9');
}

int my_wchar_islow(wchar_t c)
{
    return (c >= 'a' && c <= 'z');
}

int my_wchar_isup(wchar_t c)
{
    return (c >= 'A' && c <= 'Z');
}

int my_wchar_isalpha(wchar_t c)
{
    return my_wchar_islow(c) || my_wchar_isup(c);
}

int my_wchar_isprintable(wchar_t c)
{
    return (c >= ' ' && c <= '~');
}