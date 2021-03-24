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

void my_printf(int file, char const *str, ...);

static int show_str(int file, char const *str, int index)
{
    int i = index;

    while (str[i] != 0 && str[i] != '%') {
        i++;
    }
    write(file, str + index, i - index);
    return i;
}

void my_vprintf(int file, char const *str, va_list *valist)
{
    int index = 0;
    vprint_t infos = {0, 0, 0, 0};
    int errors[2] = {0};

    while (str[index] != 0){
        index = show_str(file, str, index);
        if (str[index] == '%'){
            index++;
            infos.flags = 0;
            errors[1] = add_flags_lengths(str, &index, &infos, 1);
            infos.width = get_width(str, &index);
            infos.precision = get_precision(str, &index);
            errors[1] += add_flags_lengths(str, &index, &infos, 0);
            infos.type = vprint_get_specifier(str, &index);
            errors[0] += vprintf_handle_format(file, &infos, valist);
        }
    }
}

static void printf_show_special_char(int file, char c)
{
    int nb_zeros = 2;
    char c_backup = c;

    my_putchar_file(file, '\\');
    while (c_backup >= 8){
        c_backup /= 8;
        nb_zeros--;
    }
    for (int i = 0; i < nb_zeros; i++){
        my_putchar_file(file, '0');
    }
    my_printf(file, "%o", c);
}

void printf_put_str_adv(int file, char const *str, int special, int size)
{
    int i = 0;

    if (!special){
        write(file, str, (size == -1) ? my_strlen(str) : size);
        return;
    }
    while (str[i] != 0 && i < size) {
        if (my_char_isprintable(str[i]))
            my_putchar_file(file, str[i]);
        else
            printf_show_special_char(file, str[i]);
        i++;
    }
}