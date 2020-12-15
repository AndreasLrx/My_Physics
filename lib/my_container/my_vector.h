/*
** EPITECH PROJECT, 2020
** My vector
** File description:
** vector header
*/

#ifndef MY_VECT_H
#define MY_VECT_H

#include <stddef.h>
#include <stdlib.h>

#define my_vector(n, t, c) t *n = (t *)my_vector_init(sizeof(t), c)

size_t *my_vector_init(size_t elmt_size, size_t capacity);

size_t my_vector_get_capacity(size_t *vec);
size_t my_vector_get_size(size_t *vec);
size_t my_vector_get_elmt_size(size_t *vec);
void my_vector_set_size(size_t *vec, size_t size);
void my_vector_set_elmt_size(size_t *vec, size_t elmt_size);
void my_vector_set_capacity(size_t *vec, size_t capacity);

void my_vector_push(size_t **vec, size_t value);
void my_vector_pop(size_t **vec);
size_t my_vector_top(size_t *vec);

int my_vector_empty(size_t *vec);

void my_vector_grow(size_t **vec, size_t new_size);
size_t *my_vector_resize(size_t *vec, size_t size);
void my_vector_free(size_t **vec);
void my_vector_free_elmt(size_t *vec, size_t pos);
void my_vector_clear(size_t *vec, int free);
void my_vector_erase(size_t *vec, size_t pos, int free);
void my_vector_insert(size_t **vec, size_t pos, size_t value);
void my_vector_replace(size_t *vec, size_t value, size_t index, int free);

#endif