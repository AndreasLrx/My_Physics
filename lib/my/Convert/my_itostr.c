/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** Convert - int to str
*/

#include <stddef.h>
#include <stdlib.h>

size_t my_number_len(int n);

char *my_itostr(int nb)
{
    int back_nb = nb;
    int size_str = my_number_len(nb);
    char *str = malloc(sizeof(char) * (size_str + 1));

    for (int i = 0; i < size_str; i++){
        str[size_str - i - 1] = back_nb % 10 + '0';
        back_nb /= 10;
    }
    str[size_str] = 0;
    return str;
}

wchar_t *my_itowstr(int nb)
{
    int back_nb = nb;
    int size_str = my_number_len(nb);
    wchar_t *str = malloc(sizeof(wchar_t) * (size_str + 1));

    for (int i = 0; i < size_str; i++){
        str[size_str - i - 1] = back_nb % 10 + '0';
        back_nb /= 10;
    }
    str[size_str] = 0;
    return str;
}