/*
** EPITECH PROJECT, 2020
** My map
** File description:
** map fcts
*/

#include <stdio.h>
#include "my_map.h"

size_t my_map_find_index(my_map_t *map, size_t key)
{
    size_t elmt_size = my_vector_get_elmt_size(map->keys);
    size_t key_sizes = my_vector_get_size(map->keys);

    for (size_t i = 0; i < key_sizes; i++){
        if (map->cmp(*((size_t *)((char *)(map->keys) + i * elmt_size)), key)){
            return i;
        }
    }
    return key_sizes;
}

size_t my_map_find(my_map_t *map, size_t key)
{
    size_t index = my_map_find_index(map, key);
    size_t key_size = my_vector_get_size(map->keys);

    if (index == key_size)
        return 0;
    return my_map_at(map, index);
}

size_t my_map_at(my_map_t *map, size_t pos)
{
    size_t elmt_size = my_vector_get_elmt_size(map->values);

    return *((size_t *)((char *)(map->values) + pos * elmt_size));
}

size_t my_map_key_at(my_map_t *map, size_t pos)
{
    size_t elmt_size = my_vector_get_elmt_size(map->keys);

    return *((size_t *)((char *)(map->keys) + pos * elmt_size));
}

size_t my_map_size(my_map_t *map)
{
    return my_vector_get_size(map->keys);
}