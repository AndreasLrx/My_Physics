/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** display - putstr
*/

#include <unistd.h>

size_t my_strlen(char const *str);

void my_putstr_file(int file, char const *str)
{
    write(file, str, my_strlen(str));
}

void my_putstr_err(char const *str)
{
    my_putstr_file(STDERR_FILENO, str);
}

void my_putstr(char const *str)
{
    my_putstr_file(STDOUT_FILENO, str);
}