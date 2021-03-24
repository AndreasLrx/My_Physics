/*
** EPITECH PROJECT, 2020
** my lib
** File description:
** printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "vprint_struct.h"

void my_prints(char *dest, char const *str, ...);

static int show_str(char **dest, char const *str, int index)
{
    int i = index;

    while (str[i] != 0 && str[i] != '%') {
        i++;
    }
    *dest = my_strncat(*dest, str + index, i - index);
    return i;
}

void my_vprints(char *dest, char const *str, va_list *valist)
{
    int index = 0;
    vprint_t infos = {0, 0, 0, 0};
    int errors[2] = {0};
    char *p = dest;

    while (str[index] != 0){
        index = show_str(&p, str, index);
        if (str[index] == '%'){
            index++;
            infos.flags = 0;
            errors[1] = add_flags_lengths(str, &index, &infos, 1);
            infos.width = get_width(str, &index);
            infos.precision = get_precision(str, &index);
            errors[1] += add_flags_lengths(str, &index, &infos, 0);
            infos.type = vprint_get_specifier(str, &index);
            errors[0] += vprints_handle_format(&p, &infos, valist);
        }
    }
}

static void prints_show_special_char(char **dest, char c)
{
    int nb_zeros = 2;
    char c_backup = c;

    *dest = my_strncat(*dest, "\\", 1);
    while (c_backup >= 8){
        c_backup /= 8;
        nb_zeros--;
    }
    for (int i = 0; i < nb_zeros; i++){
        *dest = my_strncat(*dest, "0", 1);
    }
    my_prints(*dest, "%o", c);
}

void prints_put_str_adv(char **dest, char const *str, int special, int size)
{
    int i = 0;

    if (!special){
        *dest = my_strncat(*dest, str, (size == -1) ? my_strlen(str) : size);
        return;
    }
    while (str[i] != 0 && i < size) {
        if (my_char_isprintable(str[i]))
            *dest = my_strncat(*dest, str + i, 1);
        else
            prints_show_special_char(dest, str[i]);
        i++;
    }
}