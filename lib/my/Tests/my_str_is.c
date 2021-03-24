/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** str is tests
*/

int my_char_isnum(char c);
int my_char_islow(char c);
int my_char_isup(char c);
int my_char_isalpha(char c);
int my_char_isprintable(char c);

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (!my_char_isnum(str[i]))
            return 0;
    }
    return 1;
}

int my_str_islow(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (!my_char_islow(str[i]))
            return 0;
    }
    return 1;
}

int my_str_isup(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (!my_char_isup(str[i]))
            return 0;
    }
    return 1;
}

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (!my_char_isalpha(str[i]))
            return 0;
    }
    return 1;
}

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (!my_char_isprintable(str[i]))
            return 0;
    }
    return 1;
}