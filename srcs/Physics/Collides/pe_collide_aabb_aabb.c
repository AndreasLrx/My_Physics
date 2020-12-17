/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - collide aabb & aabb fcts
*/

#include "Physics/physics.h"

char pe_collide_aabbs(pe_aabb_t *a, pe_aabb_t *b)
{
    return (!(a->max.x < b->min.x || a->min.x > b->max.x || \
    a->max.y < b->min.y || a->min.y > b->max.y));
}