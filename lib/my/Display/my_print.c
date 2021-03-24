/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** print fcts
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

void my_vprints(char *dest, char const *str, va_list *valist);
void my_vprintf(int file, char const *str, va_list *valist);
void my_strnset(char *str, char value, size_t n);
void my_putstr(char const *str);
void my_putstr_file(int file, char const *str);

void my_print(char const *str, ...)
{
    va_list list;

    va_start(list, str);
    my_vprintf(STDOUT_FILENO, str, &list);
    va_end(list);
}

void my_printf(int file, char const *str, ...)
{
    va_list list;

    va_start(list, str);
    my_vprintf(file, str, &list);
    va_end(list);
}

void my_prints(char *buffer, char *str, ...)
{
    va_list list;

    va_start(list, str);
    my_vprints(buffer, str, &list);
    va_end(list);
}