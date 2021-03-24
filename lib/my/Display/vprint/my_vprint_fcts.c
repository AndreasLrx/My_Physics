/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** vprint fcts
*/

#include "vprint_struct.h"

char vprint_get_specifier(char const *str, int *index)
{
    char specifier = 0;

    while (my_get_char_in("dioxXbucsfF%Sp", specifier) == 0 && \
    str[*index] != 0){
        specifier = str[*index];
        (*index)++;
    }
    return specifier;
}

int vprint_get_count(vprint_t *format, unsigned char neg, int *value_len)
{
    int count = 0;
    int precision = format->precision - ((format->flags & DIESE) != 0 \
    && format->type == 'o');

    if (my_get_char_in("dioxXbu", format->type) != 0){
        if (precision > *value_len)
            count += precision - *value_len;
        format->precision = (precision >= 0) ? count : 0;
    }
    if (my_get_char_in("sSfF", format->type) != 0){
        if (my_get_char_in("sS", format->type) != 0)
            *value_len = ((precision >= 0 && \
            precision <= *value_len) ? precision : *value_len);
        format->precision = 0;
    }
    if ((format->flags & SIGN_FLAGS) != 0 || format->type == 'p'){
        count += (format->type == 'p') ? 2 : 1;
        if ((format->flags & DIESE) != 0 && format->type != 'o')
            count++;
    }
    return count + *value_len + ((neg) ? ((format->flags & 12) == 0) : 0);
}