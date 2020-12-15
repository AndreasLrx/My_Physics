/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** My lib conversions
*/

#ifndef MY_LIB_CONVERT_H
#define MY_LIB_CONVERT_H

#include <stddef.h>

long int my_get_number_adv(char const *str, size_t *i, \
int is_signed, int only_num);
long int my_get_number_pass(char const *str, size_t *i);
size_t my_number_len(int n);

char *my_itostr(int nb);
wchar_t *my_itowstr(int nb);

#endif /* !MY_LIB_CONVERT_H */