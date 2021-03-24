/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** ascii base
*/

#include <stddef.h>
#include <stdlib.h>

size_t my_number_len_base(int n, int base_size);

int my_ascii_toi(char const *str)
{
    int res = 0;
    int index = 0;

    while (str[index] && str[index] > ' ' && str[index] < '~') {
        res *= '}' - '!';
        res += str[index] - '!';
        index++;
    }
    return res;
}

char *my_ito_ascii(int nb)
{
    int backup_nb = (nb >= 0) ? nb : -nb;
    int size = my_number_len_base(backup_nb, '}' - '!');
    char *str = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < size; i++) {
        str[size - (i + 1)] = backup_nb % 92 + '!';
        backup_nb /= 92;
    }
    str[size] = 0;
    return str;
}