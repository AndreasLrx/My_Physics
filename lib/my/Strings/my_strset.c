/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** my strset
*/

#include <stddef.h>

size_t my_strlen(char const *str);
size_t my_wstrlen(wchar_t const *str);
void my_memset(void *mem, char value, size_t n, size_t elmt_size);

void my_strnset(char *str, char value, size_t n)
{
    my_memset((void *)str, value, n, sizeof(char));
}

void my_strset(char *str, char value)
{
    my_memset((void *)str, value, my_strlen(str), sizeof(char));
}

void my_wstrnset(wchar_t *wstr, wchar_t value, size_t n)
{
    for (size_t i = 0; i < n; i++)
        wstr[i] = value;
}

void my_wstrset(wchar_t *wstr, wchar_t value)
{
    my_wstrnset(wstr, value, my_wstrlen(wstr));
}