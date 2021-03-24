/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** vprint formats fcts
*/

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "vprint_struct.h"

char *my_ftostr(long double nb, int precision);
char *my_tobase(long long nb, char const *base);
char *my_tobase_u(unsigned long long nb, char const *base);

static size_t vprint_get_unum(vprint_t *format, va_list *list)
{
    size_t num;

    if ((format->flags & SHORT) != 0)
        num = (unsigned short)va_arg(*list, int);
    if ((format->flags & SHORT_SHORT) != 0)
        num = (unsigned char)va_arg(*list, int);
    if ((format->flags & LONG) != 0)
        num = va_arg(*list, long unsigned int);
    if ((format->flags & LONG_LONG) != 0)
        num = va_arg(*list, long long unsigned int);
    if ((format->flags & LENGTH_MODIFIER) == 0)
        num = va_arg(*list, unsigned int);
    return num;
}

static size_t vprint_get_num(vprint_t *format, va_list *list)
{
    size_t num;

    if (my_get_char_in("uxXob", format->type) != 0)
        return vprint_get_unum(format, list);
    if (format->type == 'p')
        num = va_arg(*list, uintptr_t);
    if ((format->flags & SHORT) != 0)
        num = (short)va_arg(*list, int);
    if ((format->flags & SHORT_SHORT) != 0)
        num = (char)va_arg(*list, int);
    if ((format->flags & LONG) != 0)
        num = va_arg(*list, long int);
    if ((format->flags & LONG_LONG) != 0)
        num = va_arg(*list, long long int);
    if (format->type != 'p' && (format->flags & LENGTH_MODIFIER) == 0)
        num = va_arg(*list, int);
    return num;
}

void vprint_handle_num(void *dest, vprint_t *format, va_list *list, \
void (*show_val)(size_t *, char *, vprint_t *, unsigned char))
{
    char *value;
    long long num = vprint_get_num(format, list);

    if (num == 0 && (format->flags & DIESE) != 0)
        format->flags -= 16;
    if (my_get_char_in("diu", format->type) != 0)
        value = my_tobase(num, "0123456789");
    if (format->type == 'u')
        value = my_tobase_u(num, "0123456789");
    if (my_get_char_in("xp", format->type) != 0)
        value = my_tobase_u(num, "0123456789abcdef");
    if (format->type == 'X')
        value = my_tobase_u(num, "0123456789ABCDEF");
    if (format->type == 'o')
        value = my_tobase_u(num, "01234567");
    if (format->type == 'b')
        value = my_tobase_u(num, "01");
    show_val(dest, value, format, num < 0 && \
    my_get_char_in("diu", format->type) != 0);
    free(value);
}

void vprint_handle_floats(void *dest, vprint_t *format, va_list *list, \
void (*show_val)(size_t *, char *, vprint_t *, unsigned char))
{
    long double num;
    int precision = (format->precision >= 0) ? format->precision : 6;
    char *value;

    if ((format->flags & 128) != 0)
        num = va_arg(*list, double);
    if ((format->flags & 512) != 0)
        num = va_arg(*list, long double);
    if ((format->flags & 640) == 0)
        num = (float)va_arg(*list, double);
    value = my_ftostr(num, precision);
    show_val(dest, value, format, num < 0);
    free(value);
}