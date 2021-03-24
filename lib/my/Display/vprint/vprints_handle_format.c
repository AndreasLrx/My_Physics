/*
** EPITECH PROJECT, 2020
** my lib
** File description:
** printf handle format
*/

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "vprint_struct.h"

int vprints_handle_format(char **dest, vprint_t *format, va_list *list)
{
    if (!is_vprint_format_valid(format)){
        va_arg(*list, int);
        return 1;
    }
    if (my_get_char_in("dioxXbup", format->type) != 0){
        vprint_handle_num((size_t *)dest, format, list, prints_show_value);
        return 0;
    }
    if (my_get_char_in("fF", format->type) != 0){
        vprint_handle_floats((size_t *)dest, format, list, prints_show_value);
        return 0;
    }
    if (format->type == 's' || format->type == 'S')
        prints_show_value((size_t *)dest, va_arg(*list, char *), format, 0);
    if (format->type == 'c')
        prints_putchar(dest, va_arg(*list, int), format);
    if (format->type == '%')
        *dest = my_strncat(*dest, "%", 1);
    return 0;
}