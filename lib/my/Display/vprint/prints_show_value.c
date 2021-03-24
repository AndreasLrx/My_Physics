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

static void show_prefix(char **dest, vprint_t *format, unsigned char neg)
{
    if (my_get_char_in("ucsS", format->type) != 0)
        return;
    if (neg)
        *dest = my_strncat(*dest, "-", 1);
    if (!neg && (format->flags & 12) != 0)
        *dest = my_strncat(*dest, ((format->flags & 4) == 0) ? " " : "+", 1);
    if ((format->flags & 16) != 0) {
        *dest = my_strncat(*dest, "0", 1);
        if (format->type != 'o')
            *dest = my_strncat(*dest, &format->type, 1);
    }
    if (format->type == 'p')
        *dest = my_strncat(*dest, "0x", 2);
}

void prints_show_value(size_t *dest_ptr, char *value, \
vprint_t *format, unsigned char neg)
{
    int value_len = my_strlen(value);
    int count = vprint_get_count(format, neg, &value_len);
    char **dest = (char **)dest_ptr;

    if ((format->flags & ZERO) != 0 || (format->flags & LEFT) == LEFT){
        show_prefix(dest, format, neg);
        for (int i = 0; i < format->precision; i++)
            *dest = my_strncat(*dest, "0", 1);
    }
    if ((format->flags & LEFT) == LEFT)
        prints_put_str_adv(dest, value, format->type == 'S', value_len);
    for (int i = 0; i < format->width - count; i++)
        *dest = my_strncat(*dest, ((format->flags & ZERO) == 0) ? " " : "0", 1);
    if ((format->flags & 2) == 0 && (format->flags & 1) != 1) {
        show_prefix(dest, format, neg);
        for (int i = 0; i < format->precision; i++)
            *dest = my_strncat(*dest, "0", 1);
    }
    if ((format->flags & LEFT) == 0)
        prints_put_str_adv(dest, value, format->type == 'S', value_len);
}

void prints_putchar(char **dest, char c, vprint_t *format)
{
    if ((format->flags & LEFT) == LEFT)
        *dest = my_strncat(*dest, &c, 1);
    for (int i = 0; i < format->width - 1; i++)
        *dest = my_strncat(*dest, ((format->flags & ZERO) == 0) ? " " : "0", 1);
    if ((format->flags & LEFT) == 0)
        *dest = my_strncat(*dest, &c, 1);
}