/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - aabb copy
*/

#include "Physics/Shapes/aabb_shape.h"

pe_aabb_t *pe_aabb_copy(pe_aabb_t *dest, pe_aabb_t *src)
{
    if (dest == NULL || src == NULL)
        return dest;
    dest->min = src->min;
    dest->max = src->max;
    dest->size = pe_vec2f_operate(dest->max, dest->min, SUBSTRACT);
    return dest;
}