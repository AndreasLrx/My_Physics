/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** Conversion - Str to int
*/

#include <stddef.h>

#include <stdio.h>

int my_char_isnum(char c);

long int my_get_number_adv(char const *str, size_t *i, \
int is_signed, int only_num)
{
    long int res = 0;
    size_t index = (i) ? *i : 0;
    int neg = (is_signed && str[index] == '-');

    if (neg)
        index++;
    while (str[index] != 0 && (!only_num || my_char_isnum(str[index]))){
        res *= 10;
        res += str[index] - '0';
        index++;
    }
    if (neg)
        res *= -1;
    if (i)
        *i = index;
    return res;
}

long int my_get_number_pass(char const *str, size_t *i)
{
    long int res = my_get_number_adv(str, i, 1, 1);

    if (i && str[*i] != 0)
        (*i)++;
    return res;
}