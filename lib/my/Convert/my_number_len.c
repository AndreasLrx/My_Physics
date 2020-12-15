/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** My number len
*/

#include <stddef.h>

size_t my_number_len(int n)
{
    int len = 1 + (n < 0);
    int pos_n = (n >= 0) ? n : -n;

    while (pos_n >= 10){
        pos_n /= 10;
        len++;
    }
    return len;
}