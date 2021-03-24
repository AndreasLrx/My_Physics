/*
** EPITECH PROJECT, 2020
** my lib
** File description:
** printf get format
*/

#include <stdio.h>
#include "vprint_struct.h"

char *my_strcat(char *dest, char const *src);
int my_get_char_in(char const *str, char c);
int my_char_isnum(char const c);

int add_flag(char value, vprint_t *infos)
{
    int flag = 0;

    if (value == '-')
        flag += LEFT;
    if (value == '0')
        flag += ZERO;
    if (value == '+')
        flag += PLUS;
    if (value == ' ')
        flag += SPACE;
    if (value == '#')
        flag += DIESE;
    if ((infos->flags & flag) != 0)
        return 1;
    infos->flags += flag;
    return 0;
}

static int add_length_mod(char value, vprint_t *infos)
{
    if (value == 'h'){
        if ((infos->flags & SHORT_SHORT) != 0)
            return 1;
        infos->flags += SHORT;
    }
    if (value == 'l'){
        if ((infos->flags & LONG_LONG) != 0)
            return 1;
        infos->flags += LONG;
    }
    if (value == 'L'){
        if ((infos->flags & LONG_DOUBLE) != 0)
            return 1;
        infos->flags += LONG_DOUBLE;
    }
    return 0;
}

int add_flags_lengths(char const *str, int *index, \
vprint_t *infos, int is_flags)
{
    char flags_chars[6] = {0};
    char value;
    int error = 0;

    if (is_flags)
        my_strcat(flags_chars, "-0+ #");
    else
        my_strcat(flags_chars, "hlL");
    value = my_get_char_in(flags_chars, str[*index]);
    while (value != 0){
        (*index)++;
        error += (is_flags) ? add_flag(value, infos) : \
        add_length_mod(value, infos);
        value = my_get_char_in(flags_chars, str[*index]);
    }
    return (error > 0);
}

int get_width(char const *str, int *index)
{
    int result = 0;

    while (my_char_isnum(str[*index])){
        result *= 10;
        result += str[*index] - '0';
        (*index)++;
    }
    return result;
}

int get_precision(char const *str, int *index)
{
    int neg = 0;

    if (str[*index] != '.') {
        return -1;
    } else {
        (*index)++;
    }
    if (str[*index] == '-'){
        neg++;
        (*index)++;
    }
    return (neg) ? -2 : get_width(str, index);
}