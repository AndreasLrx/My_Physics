/*
** EPITECH PROJECT, 2020
** my lib
** File description:
** printf struct
*/

#ifndef PRINTF_STRUCT_H
#define PRINTF_STRUCT_H

#include <stddef.h>
#include <stdarg.h>

enum PRINTF_FLAGS {LEFT = 1, ZERO = 2, PLUS = 4, SPACE = 8, \
DIESE = 16, SHORT = 32, SHORT_SHORT = 64, LONG = 128, \
LONG_LONG = 256, LONG_DOUBLE = 512};

enum PRINTF_MASKS {LENGTH_MODIFIER = 480, SIGN_FLAGS = 28, BASIC_FLAGS = 31};

typedef struct {
    int flags;
    char type;
    int width;
    int precision;
} vprint_t;

int is_vprint_format_valid(vprint_t *format);
int vprint_get_count(vprint_t *format, unsigned char neg, int *value_len);
char vprint_get_specifier(char const *str, int *index);
int my_get_char_in(char const *str, char c);
size_t my_strlen(char const *str);
int my_char_isprintable(char c);

int add_flag(char value, vprint_t *infos);
int add_flags_lengths(char const *str, int *index, \
vprint_t *infos, int is_flags);
int get_width(char const *str, int *index);
int get_precision(char const *str, int *index);

int vprintf_handle_format(size_t file, vprint_t *format, va_list *list);
void my_putstr_file(int file, char const *str);
void my_putchar_file(int file, char c);
void printf_putchar(int file, char c, vprint_t *format);
void printf_show_value(size_t *file, char *value, \
vprint_t *format, unsigned char neg);
void printf_put_str_adv(int file, char const *str, int special, int size);

int vprints_handle_format(char **dest, vprint_t *format, va_list *list);
char *my_strncat(char *dest, char const *str, size_t n);
void prints_putchar(char **dest, char c, vprint_t *format);
void prints_show_value(size_t *dest, char *value, \
vprint_t *format, unsigned char neg);
void prints_put_str_adv(char **dest, char const *str, int special, int size);

void vprint_handle_num(void *dest, vprint_t *format, va_list *list, \
void (*show_val)(size_t *, char *, vprint_t *, unsigned char));
void vprint_handle_floats(void *dest, vprint_t *format, va_list *list, \
void (*show_val)(size_t *, char *, vprint_t *, unsigned char));

#endif