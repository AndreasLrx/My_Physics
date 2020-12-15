/*
** EPITECH PROJECT, 2020
** My map
** File description:
** map header
*/

#ifndef MY_MAP_H
#define MY_MAP_H

#include "./my_vector.h"

#define my_map(k_type, v_type, cmp, p1, p2) my_map_init\
(sizeof(k_type), sizeof(v_type), &cmp, 2 * p1 + p2)

typedef struct my_map_t {
    size_t *keys;
    size_t *values;
    unsigned char is_ptrs;
    int (*cmp)(size_t, size_t);
} my_map_t;


my_map_t *my_map_init(size_t key_size, size_t value_size, \
int (*cmp)(size_t, size_t), unsigned char ptrs);
void my_map_insert(my_map_t *map, size_t key, size_t value);
size_t my_map_find_index(my_map_t *map, size_t key);
size_t my_map_find(my_map_t *map, size_t key);
size_t my_map_size(my_map_t *map);
size_t my_map_at(my_map_t *map, size_t pos);
size_t my_map_key_at(my_map_t *map, size_t pos);
void my_map_clear(my_map_t *map);
int my_map_empty(my_map_t *map);
void my_map_erase_index(my_map_t *map, size_t index);
void my_map_erase_key(my_map_t *map, size_t key);
void my_map_free(my_map_t **map);

#endif