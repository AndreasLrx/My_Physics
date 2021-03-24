/*
** EPITECH PROJECT, 2020
** Epitech Day06
** File description:
** str comp
*/

#include <stddef.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return 0;
    while (*s1 != '\0' && *s1 == *s2 && i < n){
        s1++;
        s2++;
        i++;
    }
    if (i < n && *s1 != *s2){
        return *s1 - *s2;
    } else {
        return 0;
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return 0;
    while (*s1 != '\0' && *s1 == *s2){
        s1++;
        s2++;
    }
    if (*s1 != *s2){
        return *s1 - *s2;
    } else {
        return 0;
    }
}

int my_wstrncmp(wchar_t const *s1, wchar_t const *s2, int n)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return 0;
    while (*s1 != '\0' && *s1 == *s2 && i < n){
        s1++;
        s2++;
        i++;
    }
    if (*s1 != *s2){
        return *s1 - *s2;
    } else {
        return 0;
    }
}

int my_wstrcmp(wchar_t const *s1, wchar_t const *s2)
{
    if (s1 == NULL || s2 == NULL)
        return 0;
    while (*s1 != '\0' && *s1 == *s2){
        s1++;
        s2++;
    }
    if (*s1 != *s2){
        return *s1 - *s2;
    } else {
        return 0;
    }
}