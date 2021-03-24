/*
** EPITECH PROJECT, 2021
** MyWorld
** File description:
** str_to_tab.c
*/

#include <stddef.h>
#include <stdlib.h>

void my_strncpy(char *dest, char const *src, size_t n);

static int count_word(char *str)
{
    int nb = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            nb++;
    return (nb);
}

char **my_str_to_tab(char *str, char sep)
{
    int	j = 0;
    int	i = 0;
    int	len = 0;
    char **tab = malloc(sizeof(*(tab)) * (count_word(str) + 1));

    while (str[i]) {
        if (str[i] != sep)
            len++;
        if (str[i] != sep && str[i + 1] == sep) {
            tab[j] = malloc(len + 1);
            my_strncpy(tab[j], &str[i - len + 1], len);
            len = 0;
            j++;
        }
        i++;
    }
    tab[j] = NULL;
    return (tab);
}
