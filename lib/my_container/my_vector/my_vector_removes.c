/*
** EPITECH PROJECT, 2020
** My Vectors
** File description:
** vector removes fcts -clear free insert
*/

#include "my_vector.h"

void my_vector_free(size_t **vec)
{
    size_t *beg_vec = &(*vec)[-3];

    free(beg_vec);
    *vec = NULL;
}

void my_vector_free_elmt(size_t *vec, size_t pos)
{
    free(*((size_t **)((char *)(vec) + pos * my_vector_get_elmt_size(vec))));
}

void my_vector_clear(size_t *vec, int free)
{
    size_t size = my_vector_get_size(vec);

    for (int i = 0; i < size; i++){
        if (free)
            my_vector_free_elmt(vec, i);
        my_vector_pop(&vec);
    }
}

void my_vector_erase(size_t *vec, size_t pos, int free)
{
    size_t elmt_size = my_vector_get_elmt_size(vec);
    size_t vec_size = my_vector_get_size(vec);

    if (free)
        my_vector_free_elmt(vec, pos);
    for (size_t i = pos; i < vec_size - 1; i++) {
        for (size_t byte = 0; byte < elmt_size; byte++){
            *((char *)(vec) + i * elmt_size + byte) = \
            *((char *)(vec) + (i + 1) * elmt_size + byte);
        }
    }
    my_vector_pop(&vec);
}