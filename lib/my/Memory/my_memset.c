/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** my memset
*/

#include <stddef.h>

void my_memset(void *mem, char value, size_t n, size_t elmt_size)
{
    char *mem_bytes = (char *)mem;
    size_t nb_bytes = n * elmt_size;

    for (size_t i = 0; i < nb_bytes; i++)
        mem_bytes[i] = value;
}