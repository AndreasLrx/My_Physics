/*
** EPITECH PROJECT, 2020
** My Lib
** File description:
** tests - char
*/

int my_char_isnum(char c)
{
    return (c >= '0' && c <= '9');
}

int my_char_islow(char c)
{
    return (c >= 'a' && c <= 'z');
}

int my_char_isup(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int my_char_isalpha(char c)
{
    return my_char_islow(c) || my_char_isup(c);
}

int my_char_isprintable(char c)
{
    return (c >= ' ' && c <= '~');
}