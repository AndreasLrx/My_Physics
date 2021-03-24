/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** Display fcts
*/

#ifndef MY_LIB_DISPLAY_H
#define MY_LIB_DISPLAY_H

void my_putchar_file(int file, char c);
void my_putchar_err(char c);
void my_putchar(char c);

void my_putstr_file(int file, char const *str);
void my_putstr_err(char const *str);
void my_putstr(char const *str);

void my_print(char const *str, ...);
void my_printf(int file, char const *str, ...);
void my_prints(char *buffer, char *str, ...);

#endif /* !MY_LIB_DISPLAY_H */