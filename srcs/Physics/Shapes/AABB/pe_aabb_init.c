/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - aabb init
*/

#include "Physics/physics.h"

void pe_aabb_init(pe_aabb_t *aabb, pe_vec2f_t min, pe_vec2f_t max, int is_point)
{
    aabb->min = min;
    aabb->max = (is_point) ? min : max;
    aabb->size = VEC2F_SUB(aabb->max, aabb->min);
}