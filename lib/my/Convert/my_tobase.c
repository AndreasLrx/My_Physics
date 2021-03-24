/*
** EPITECH PROJECT, 2020
** Epitech pool lib
** File description:
** int to base
*/

#include <stdlib.h>
#include "macro.h"

int my_strlen(char const *str);
char *my_strset(char *src, char c);
void *my_calloc(size_t size, char value);

static int get_nb_bits(unsigned long long nbr)
{
    int bits = 1;
    unsigned long long bit_value = 1;
    unsigned long long backup_nb = nbr;

    while (backup_nb > bit_value && bits < (int)(sizeof(nbr) * 8)){
        bit_value *= 2;
        bits++;
    }
    return bits;
}

static float get_nearest_pow(int base_size)
{
    unsigned long long int current_pow = 1;
    int power = 0;

    if (base_size == 3)
        return 1.6;
    while (base_size >= current_pow){
        current_pow *= 2;
        power++;
    }
    return power;
}

static char *remove_blanks(int strlen, int index, char *str)
{
    if (strlen - index != 0){
        for (int i = 1; i < index + 1; i++)
            str[i] = str[i + strlen - index - 2];
        for (int i = index + 1; i < strlen; i++)
            str[i] = 0;
    }
    return str;
}

char *my_tobase(long long nb, char const *base)
{
    long long backup = ABS(nb);
    int base_size = my_strlen(base);
    int strlen = 2 + get_nb_bits(backup) / (get_nearest_pow(base_size) - 1);
    char *str = my_calloc(strlen, 0);
    int index = 0;

    while (backup >= base_size){
        str[strlen - (index + 2)] = base[backup % base_size];
        backup /= base_size;
        index++;
    }
    str[0] = base[backup];
    return remove_blanks(strlen, index, str);
}

char *my_tobase_u(unsigned long long nb, char const *base)
{
    unsigned long long backup = nb;
    int base_size = my_strlen(base);
    int strlen = 2 + get_nb_bits(backup) / (get_nearest_pow(base_size) - 1);
    char *str = malloc(strlen);
    int index = 0;

    my_strset(str, 0);
    while (backup >= base_size){
        str[strlen - (index + 2)] = base[backup % base_size];
        backup /= base_size;
        index++;
    }
    str[0] = base[backup];
    return remove_blanks(strlen, index, str);
}