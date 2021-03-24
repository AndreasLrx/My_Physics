/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** Display - putchar
*/

#include <unistd.h>

void my_putchar_file(int file, char c)
{
    write(file, &c, 1);
}

void my_putchar(char c)
{
    my_putchar_file(STDOUT_FILENO, c);
}

void my_putchar_err(char c)
{
    my_putchar_file(STDERR_FILENO, c);
}