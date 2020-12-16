/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics vec2i
*/

#include "Physics/Utils/utils.h"

int pe_vec2i_cmp(pe_vec2i_t v1, pe_vec2i_t v2)
{
    return (v1.x == v2.x && v1.y == v2.y);
}

long pe_vec2i_tol(pe_vec2i_t vec)
{
    long value = vec.x;

    value <<= 32;
    value += vec.y;
    return value;
}

int pe_vec2i_map_cmp(size_t v1, size_t v2)
{
    return (v1 == v2);
}