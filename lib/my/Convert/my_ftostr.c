/*
** EPITECH PROJECT, 2020
** Epitech rush_2
** File description:
** my put float
*/

#include <limits.h>
#include <stdlib.h>

char *my_itostr(int nbr);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
int my_pow_i(int n, int p);
char *my_tobase(long long nb, char const *base);

static void free_mem(char *real, char *float_part, int real_n, int float_nb)
{
    if (real_n != INT_MIN)
        free(real);
    free(float_part);
}

static void set_precision(int precision, char *result, char *float_part_str)
{
    if (precision > 0){
        my_strcat(result, ".");
        for (int i = 0; i < precision - my_strlen(float_part_str); i++)
            my_strcat(result, "0");
        my_strcat(result, float_part_str);
    }
}

char *my_ftostr(long double nb, int precision)
{
    long long real = (long long) nb;
    long long float_part = (long long)((float)((nb - real) * \
    my_pow_i(10, precision)) + 0.5);
    char *real_str = my_tobase(real, "0123456789");
    char *float_part_str = my_tobase(float_part + 0.5, "0123456789");
    int size = my_strlen(real_str) + (1 + precision) * (precision > 0);
    char *result = malloc(size + 1);

    for (int i = 0; i < size + 1; i++)
        result[i] = 0;
    my_strcat(result, real_str);
    set_precision(precision, result, float_part_str);
    for (int i = 0; i < size; i++){
        if (result[i] == 0)
            result[i] = '0';
    }
    free_mem(real_str, float_part_str, real, float_part);
    return result;
}
