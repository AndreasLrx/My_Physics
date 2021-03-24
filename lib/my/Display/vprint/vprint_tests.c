/*
** EPITECH PROJECT, 2020
** my lib
** File description:
** printf handle format
*/

#include <stdio.h>
#include "vprint_struct.h"

int my_get_char_in(char const *str, char c);

static void check_conflicting_flags(vprint_t *format)
{
    if ((format->flags & (ZERO + LEFT)) == 3)
        format->flags -= ZERO;
    if ((format->flags & SIGN_FLAGS) != 0){
        if ((format->flags & (PLUS + SPACE)) == (PLUS + SPACE))
            format->flags -= SPACE;
        if ((format->flags & SIGN_FLAGS) > DIESE && \
            my_get_char_in("bxXo", format->type) == 0)
            format->flags -= DIESE;
        if ((format->flags & SIGN_FLAGS) > DIESE && \
            my_get_char_in("difF", format->type) == 0)
            format->flags -= (format->flags & (PLUS + SPACE));
    }
    if (((format->flags & (SHORT + SHORT_SHORT)) != 0 && \
        (format->flags & (LONG + LONG_LONG)) != 0) || \
        ((format->flags & LONG_DOUBLE) != 0 && \
        (format->flags & LENGTH_MODIFIER) != 0))
        format->flags &= BASIC_FLAGS;
}

static void check_flags_coherence(vprint_t *format)
{
    if ((format->flags & ZERO) != 0 && \
        my_get_char_in("csSp", format->type) != 0)
        format->flags -= ZERO;
    if ((format->flags & SIGN_FLAGS) != 0){
        if (my_get_char_in("dioxXbfF", format->type) == 0)
            format->flags -= (format->flags & SIGN_FLAGS);
        if ((format->flags & DIESE) != 0 && \
            my_get_char_in("bxXo", format->type) == 0)
            format->flags -= DIESE;
        if ((format->flags & (SPACE + PLUS)) != 0 && \
            my_get_char_in("difF", format->type) == 0)
            format->flags -= (format->flags & (SPACE + PLUS));
    }
    if ((format->flags & LENGTH_MODIFIER) != 0 && \
        my_get_char_in("dioxXbufF", format->type) == 0)
        format->flags &= BASIC_FLAGS;
    if ((format->flags & LONG_DOUBLE) != 0 && \
        my_get_char_in("fF", format->type) == 0)
        format->flags -= LONG_DOUBLE;
}

int is_vprint_format_valid(vprint_t *format)
{
    if (my_get_char_in("dioxXbucsS%pfF", format->type) == 0)
        return 0;
    check_conflicting_flags(format);
    check_flags_coherence(format);
    if (my_get_char_in("c%p", format->type) != 0 && format->precision != -1)
        format->precision = -1;
    return 1;
}