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

int vprintf_handle_format(size_t file, vprint_t *format, va_list *list)
{
    if (!is_vprint_format_valid(format)){
        va_arg(*list, int);
        return 1;
    }
    if (my_get_char_in("dioxXbup", format->type) != 0){
        vprint_handle_num((void *)file, format, list, printf_show_value);
        return 0;
    }
    if (my_get_char_in("fF", format->type) != 0){
        vprint_handle_floats((void *)file, format, list, printf_show_value);
        return 0;
    }
    if (format->type == 's' || format->type == 'S')
        printf_show_value((size_t *)file, va_arg(*list, char *), format, 0);
    if (format->type == 'c')
        printf_putchar(file, va_arg(*list, int), format);
    if (format->type == '%')
        my_putchar_file(file, '%');
    return 0;
}