/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** Conversion - Str to int
*/

#include <stddef.h>

double my_pow(double p, int n);
size_t my_number_len(int n);
long int my_get_number_adv(char const *str, size_t *i, \
int is_signed, int only_num);

double my_get_float_adv(char const *str, size_t *i, \
int is_signed, int only_num)
{
    size_t current_i = (i) ? *i : 0;
    int neg = (is_signed && str[current_i] == '-');
    double res;
    long int decimal = 0;
    size_t decimal_len = 0;
    size_t start_i = current_i + neg;

    current_i += neg;
    res = my_get_number_adv(str, &current_i, 0, only_num);
    if (str[current_i] == '.') {
        current_i++;
        decimal = my_get_number_adv(str, &current_i, is_signed, only_num);
    }
    decimal_len = current_i - (start_i + my_number_len(res) + 1);
    res += decimal / my_pow(10, decimal_len);
    if (i)
        (*i) = current_i;
    return res * ((neg) ? -1 : 1);
}

double my_get_float_pass(char const *str, size_t *i)
{
    double res = my_get_float_adv(str, i, 1, 1);

    if (i && str[*i] != 0)
        (*i)++;
    return res;
}