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
long int my_get_wnumber_adv(wchar_t const *str, size_t *i, \
int is_signed, int only_num);
long int my_get_wnumber_pass(wchar_t const *str, size_t *i);
int my_ascii_toi(char const *str);

size_t my_number_len_base(int n, int base_size);
size_t my_number_len(int n);

double my_get_float_adv(char const *str, size_t *i, \
int is_signed, int only_num);
double my_get_float_pass(char const *str, size_t *i);
char *my_ftostr(long double nb, int precision);

char *my_ito_ascii(int nb);
char *my_itostr(int nb);
wchar_t *my_itowstr(int nb);

char *my_tobase(long long nb, char const *base);
char *my_tobase_u(unsigned long long nb, char const *base);

#endif /* !MY_LIB_CONVERT_H */
