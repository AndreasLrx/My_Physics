/*
** EPITECH PROJECT, 2020
** Epitech rush_2
** File description:
** my put float
*/

int my_get_char_in(char const *str, char c)
{
    int index = 0;

    while (str[index] != 0 && str[index] != c)
        index++;
    return str[index];
}