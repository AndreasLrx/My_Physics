/*
** EPITECH PROJECT, 2020
** My Vectors
** File description:
** vector resizes fcts -pop push insert
*/

#include <stdio.h>
#include "my_vector.h"

void my_vector_grow(size_t **vec, size_t new_size)
{
    size_t size_need = new_size * my_vector_get_elmt_size(*vec) + \
    (sizeof(size_t) * 3);
    size_t *vect_infos;
    size_t *vect_alloc;

    if (!(*vec)) {
        vect_alloc = malloc(size_need);
        if (!vect_alloc)
            return;
        *vec = &vect_alloc[3];
        my_vector_set_capacity(*vec, new_size);
        my_vector_set_size(*vec, 0);
    } else {
        vect_infos = &(*vec)[-3];
        vect_alloc = my_vector_resize(vect_infos, size_need);
        if (!vect_alloc)
            return;
        *vec = (size_t *)(&vect_alloc[3]);
        my_vector_set_capacity(*vec, new_size);
    }
}

void my_vector_push(size_t **vec, size_t value)
{
    size_t capacity = my_vector_get_capacity(*vec);

    if (capacity <= my_vector_get_size(*vec)){
        my_vector_grow(vec, capacity + 1);
    }
    for (size_t i = 0; i < my_vector_get_elmt_size(*vec); i++){
        *((char *)(*vec) + my_vector_get_size(*vec) * \
        my_vector_get_elmt_size(*vec) + i) = *((char *)(&value) + i);
    }
    my_vector_set_size(*vec, my_vector_get_size(*vec) + 1);
}

void my_vector_insert(size_t **vec, size_t pos, size_t value)
{
    size_t elmt_size = my_vector_get_elmt_size(*vec);
    size_t vec_size = my_vector_get_size(*vec);
    size_t capacity = my_vector_get_capacity(*vec);

    if (capacity <= vec_size + 1){
        my_vector_grow(vec, capacity + 1);
    }
    for (size_t i = vec_size; i > pos; i--) {
        for (size_t byte = 0; byte < elmt_size; byte++){
            *((char *)(*vec) + i * elmt_size + byte) = \
            *((char *)(*vec) + (i - 1) * elmt_size + byte);
        }
    }
    for (size_t byte = 0; byte < elmt_size; byte++){
        *((char *)(*vec) + pos * elmt_size + byte) = *((char *)(&value) + byte);
    }
    my_vector_set_size(*vec, my_vector_get_size(*vec) + 1);
}

void my_vector_pop(size_t **vec)
{
    my_vector_set_size(*vec, my_vector_get_size(*vec) - 1);
}

size_t *my_vector_resize(size_t *vec, size_t size)
{
    size_t *new_vec = malloc(size);
    size_t elmt_size = ((size_t *)(vec))[0];
    size_t vect_size = (elmt_size * ((size_t *)(vec))[1]) + \
    (sizeof(size_t) * 3);
    size_t copy_size = (((vect_size < size) ? vect_size : size) - \
    (sizeof(size_t) * 3)) / elmt_size;

    for (int i = 0; i < 3; i++)
        new_vec[i] = vec[i];
    for (size_t i = 0; i < copy_size * elmt_size; i++){
        *((char *)new_vec + 3 * sizeof(size_t) + i) = \
        *((char *)vec + 3 * sizeof(size_t) + i);
    }
    free(vec);
    return new_vec;
}