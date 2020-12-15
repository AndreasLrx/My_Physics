/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** my calloc
*/

#include <stdlib.h>

void *my_calloc(size_t size, char value)
{
    char *mem = malloc(size);

    for (size_t i = 0; i < size; i++)
        mem[i] = value;
    return (void *)mem;
}