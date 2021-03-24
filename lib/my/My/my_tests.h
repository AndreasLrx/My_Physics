/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** my tests
*/

#ifndef MY_LIB_TESTS_H
#define MY_LIB_TESTS_H

#include <stddef.h>

int my_char_isnum(char c);
int my_char_islow(char c);
int my_char_isup(char c);
int my_char_isalpha(char c);
int my_char_isprintable(char c);

int my_str_isnum(char const *str);
int my_str_islow(char const *str);
int my_str_isup(char const *str);
int my_str_isalpha(char const *str);
int my_str_isprintable(char const *str);

int my_wchar_isnum(wchar_t c);
int my_wchar_islow(wchar_t c);
int my_wchar_isup(wchar_t c);
int my_wchar_isalpha(wchar_t c);
int my_wchar_isprintable(wchar_t c);

#endif /* !MY_LIB_TESTS_H */