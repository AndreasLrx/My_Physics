/*
** EPITECH PROJECT, 2020
** My map
** File description:
** map fcts
*/

#include <stdio.h>
#include "my_map.h"

my_map_t *my_map_init(size_t key_size, size_t value_size, \
int (*cmp)(size_t, size_t), unsigned char ptrs)
{
    my_map_t *map;

    if (cmp == NULL)
        return NULL;
    map = malloc(sizeof(my_map_t));
    map->keys = my_vector_init(key_size, 0);
    map->values = my_vector_init(value_size, 0);
    map->cmp = cmp;
    map->is_ptrs = ptrs;
    return map;
}

void my_map_insert(my_map_t *map, size_t key, size_t value)
{
    size_t key_size = my_vector_get_size(map->keys);
    size_t index = my_map_find_index(map, key);

    if (index != key_size){
        my_vector_replace(map->values, value, index, (map->is_ptrs & 1));
    } else {
        my_vector_push(&map->keys, key);
        my_vector_push(&map->values, value);
    }
}