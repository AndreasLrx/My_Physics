/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** display - putstr
*/

#include <unistd.h>

size_t my_strlen(char const *str);

void my_putstr_adv(int canal, char const *str)
{
    write(canal, str, my_strlen(str));
}

void my_putstr_err(char const *str)
{
    my_putstr_adv(2, str);
}

void my_putstr(char const *str)
{
    my_putstr_adv(1, str);
}