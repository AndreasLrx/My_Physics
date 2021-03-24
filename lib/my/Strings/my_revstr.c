/*
** EPITECH PROJECT, 2021
** My lib
** File description:
** my revstr
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_revstr(char *str)
{
    int size_str = my_strlen(str);
    int midsize_str = size_str / 2;
    char tempo;

    for (int i = 0; i < midsize_str; i++) {
        tempo = str[i];
        str[i] = str[size_str - (i + 1)];
        str[size_str - (i + 1)] = tempo;
    }
    return str;
}