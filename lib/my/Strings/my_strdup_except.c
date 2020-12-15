/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** wide str dup exceptiong chars
*/

#include <stddef.h>
#include <stdlib.h>

size_t my_wstrlen(wchar_t const *wstr);

static wchar_t *fill_output(wchar_t *output, wchar_t const *src, \
wchar_t except, size_t size_str)
{
    int output_i = 0;

    for (int i = 0; i < size_str; i++){
        if (src[i] != except){
            output[output_i] = src[i];
            output_i++;
        }
    }
    output[output_i] = 0;
    return output;
}

wchar_t *my_wstrdup_except(wchar_t const *src, wchar_t except)
{
    int nb_exceptions = 0;
    size_t size_str = my_wstrlen(src);
    wchar_t *output;

    if (src == NULL)
        return NULL;
    for (int i = 0; i < size_str; i++)
        nb_exceptions += (src[i] == except);
    output = malloc(sizeof(wchar_t) * (size_str - nb_exceptions + 1));
    fill_output(output, src, except, size_str);
    return output;
}