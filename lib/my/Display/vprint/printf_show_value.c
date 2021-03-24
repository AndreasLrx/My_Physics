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
#include "vprint_struct.h"

static void show_prefix(int file, vprint_t *format, unsigned char neg)
{
    if (my_get_char_in("ucsS", format->type) != 0)
        return;
    if (neg)
        my_putchar_file(file, '-');
    if (!neg && (format->flags & 12) != 0)
        my_putchar_file(file, ((format->flags & 4) == 0) ? ' ' : '+');
    if ((format->flags & 16) != 0) {
        my_putchar_file(file, '0');
        if (format->type != 'o')
            my_putchar_file(file, format->type);
    }
    if (format->type == 'p')
        my_putstr_file(file, "0x");
}

void printf_show_value(size_t *file_ptr, char *value, \
vprint_t *format, unsigned char neg)
{
    int file = (size_t)file_ptr;
    int value_len = my_strlen(value);
    int count = vprint_get_count(format, neg, &value_len);

    if ((format->flags & ZERO) != 0 || (format->flags & LEFT) == LEFT){
        show_prefix(file, format, neg);
        for (int i = 0; i < format->precision; i++)
            my_putchar_file(file, '0');
    }
    if ((format->flags & LEFT) == LEFT)
        printf_put_str_adv(file, value, format->type == 'S', value_len);
    for (int i = 0; i < format->width - count; i++)
        my_putchar_file(file, ((format->flags & ZERO) == 0) ? ' ' : '0');
    if ((format->flags & 2) == 0 && (format->flags & 1) != 1) {
        show_prefix(file, format, neg);
        for (int i = 0; i < format->precision; i++)
            my_putchar_file(file, '0');
    }
    if ((format->flags & LEFT) == 0)
        printf_put_str_adv(file, value, format->type == 'S', value_len);
}

void printf_putchar(int file, char c, vprint_t *format)
{
    if ((format->flags & LEFT) == LEFT)
        my_putchar_file(file, c);
    for (int i = 0; i < format->width - 1; i++)
        my_putchar_file(file, ((format->flags & ZERO) == 0) ? ' ' : '0');
    if ((format->flags & LEFT) == 0)
        my_putchar_file(file, c);
}