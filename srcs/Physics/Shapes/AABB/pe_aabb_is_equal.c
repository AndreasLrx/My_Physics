/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - aabb is equal
*/

#include "Physics/physics.h"

char pe_aabb_is_equal(pe_aabb_t *a, pe_aabb_t *b)
{
    return (pe_vec2f_cmp(a->min, b->min) && pe_vec2f_cmp(a->max, b->max));
}