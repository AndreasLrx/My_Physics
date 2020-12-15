/*
** EPITECH PROJECT, 2020
** My lib
** File description:
** my memory fcts
*/

#ifndef MY_LIB_MEMORY_H
#define MY_LIB_MEMORY_H

#include <stddef.h>

void my_memset(void *mem, char value, size_t n, size_t elmt_size);
void *my_calloc(size_t size, char value);

#endif /* !MY_LIB_MEMORY_H */