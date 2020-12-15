/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - AABB union
*/

#include "Physics/physics.h"

pe_aabb_t *pe_aabb_union(pe_aabb_t *res, pe_aabb_t *a, pe_aabb_t *b)
{
    if ((a == NULL && b == NULL) || res == NULL)
        return res;
    if (a == NULL)
        return pe_aabb_copy(res, b);
    if (b == NULL)
        return pe_aabb_copy(res, a);
    res->min.x = MIN(a->min.x, b->min.x);
    res->min.y = MIN(a->min.y, b->min.y);
    res->max.x = MAX(a->max.x, b->max.x);
    res->max.y = MAX(a->max.y, b->max.y);
    res->size = pe_vec2f_operate(res->max, res->min, SUBSTRACT);
    return res;
}

pe_aabb_t *pe_aabb_union_shape(pe_aabb_t *res, pe_aabb_t *a, \
pe_shape_t *shape, pe_vec2f_t offset)
{
    pe_aabb_t tempo;

    pe_aabb_from_shape(&tempo, shape);
    tempo.min = VEC2F_ADD(tempo.min, offset);
    tempo.max = VEC2F_ADD(tempo.max, offset);
    return pe_aabb_union(res, &tempo, a);
}