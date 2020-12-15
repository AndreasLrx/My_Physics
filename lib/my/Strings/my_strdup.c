/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** my strdup
*/

#include <stdlib.h>

size_t my_strlen(char const *str);
size_t my_wstrlen(wchar_t const *str);
void my_strnset(char *str, char value, size_t n);
void my_wstrnset(wchar_t *str, wchar_t value, size_t n);

char *my_strndup(char const *str, size_t n)
{
    char *new_str;
    size_t i = 0;

    if (str == NULL)
        return NULL;
    new_str = malloc(sizeof(char) * (n + 1));
    while (str[i] != 0 && i < n){
        new_str[i] = str[i];
        i++;
    }
    while (i < n + 1) {
        new_str[i] = 0;
        i++;
    }
    return new_str;
}

char *my_strdup(char const *str)
{
    if (str == NULL)
        return NULL;
    return my_strndup(str, my_strlen(str));
}

wchar_t *my_wstrndup(wchar_t const *str, size_t n)
{
    wchar_t *new_str;
    size_t i = 0;

    if (str == NULL)
        return NULL;
    new_str = malloc(sizeof(wchar_t) * (n + 1));
    while (str[i] != 0 && i < n){
        new_str[i] = str[i];
        i++;
    }
    while (i < n + 1) {
        new_str[i] = 0;
        i++;
    }
    return new_str;
}

wchar_t *my_wstrdup(wchar_t const *str)
{
    if (str == NULL)
        return NULL;
    return my_wstrndup(str, my_wstrlen(str));
}