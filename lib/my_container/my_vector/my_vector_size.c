/*
** EPITECH PROJECT, 2020
** My Vectors
** File description:
** vector sizes fcts
*/

#include "my_vector.h"

size_t my_vector_get_size(size_t *vec)
{
    if (vec){
        return vec[-2];
    } else {
        return (size_t)0;
    }
}

size_t my_vector_get_elmt_size(size_t *vec)
{
    if (vec) {
        return vec[-3];
    } else {
        return (size_t)0;
    }
}

void my_vector_set_size(size_t *vec, size_t size)
{
    if (vec){
        vec[-2] = size;
    }
}

void my_vector_set_elmt_size(size_t *vec, size_t elmt_size)
{
    if (vec){
        vec[-3] = elmt_size;
    }
}

size_t my_vector_top(size_t *vec)
{
    size_t elmt = 0;
    size_t index = my_vector_get_size(vec) - 1;
    size_t elmt_size = my_vector_get_elmt_size(vec);

    if (index < 0)
        return 0;
    for (int i = 0; i < elmt_size; i++)
        *(((char *)(&elmt)) + i) = *((char *)vec + index * elmt_size + i);
    return elmt;
}