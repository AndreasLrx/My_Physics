/*
** EPITECH PROJECT, 2020
** my_vector
** File description:
** fcts
*/

#include "my_vector.h"

size_t my_vector_get_capacity(size_t *vec)
{
    if (vec){
        return vec[-1];
    } else {
        return (size_t)0;
    }
}

void my_vector_set_capacity(size_t *vec, size_t capacity)
{
    if (vec){
        vec[-1] = capacity;
    }
}

size_t *my_vector_init(size_t elmt_size, size_t capacity)
{
    size_t size_need = capacity * elmt_size + (sizeof(size_t) * 3);
    size_t *vect = malloc(size_need);

    if (!vect) {
        return NULL;
    }
    vect = &vect[3];
    my_vector_set_capacity(vect, capacity);
    my_vector_set_size(vect, 0);
    my_vector_set_elmt_size(vect, elmt_size);
    return vect;
}

int my_vector_empty(size_t *vec)
{
    return (my_vector_get_size(vec) == 0);
}

void my_vector_replace(size_t *vec, size_t value, size_t index, int free)
{
    size_t elmt_size = my_vector_get_elmt_size(vec);

    if (free)
        my_vector_free_elmt(vec, index);
    for (size_t i = 0; i < elmt_size; i++){
        *((char *)(vec) + index * elmt_size + i) = *((char *)(&value) + i);
    }
}