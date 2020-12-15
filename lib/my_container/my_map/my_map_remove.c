/*
** EPITECH PROJECT, 2020
** My map
** File description:
** map fcts
*/

#include <stdio.h>
#include "my_map.h"

void my_map_clear(my_map_t *map)
{
    my_vector_clear(map->keys, (map->is_ptrs & 2) > 0);
    my_vector_clear(map->values, (map->is_ptrs & 1));
}

int my_map_empty(my_map_t *map)
{
    return my_vector_empty(map->keys);
}

void my_map_erase_index(my_map_t *map, size_t index)
{
    my_vector_erase(map->keys, index, (map->is_ptrs & 2) > 0);
    my_vector_erase(map->values, index, (map->is_ptrs & 1));
}

void my_map_erase_key(my_map_t *map, size_t key)
{
    size_t key_size = my_vector_get_size(map->keys);
    size_t index = my_map_find_index(map, key);

    if (index != key_size){
        my_map_erase_index(map, index);
    }
}

void my_map_free(my_map_t **map)
{
    my_map_clear(*map);
    my_vector_free((size_t **)&(*map)->keys);
    my_vector_free((size_t **)&(*map)->values);
    free(*map);
    *map = NULL;
}