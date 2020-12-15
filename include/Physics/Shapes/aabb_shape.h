/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - AABB
*/

#ifndef PHYSICS_AABB_H
#define PHYSICS_AABB_H

#include "../Utils/utils.h"

struct pe_shape_t;

typedef struct pe_aabb_t {
    pe_vec2f_t min;
    pe_vec2f_t max;
    pe_vec2f_t size;
} pe_aabb_t;

char pe_collide_aabbs(pe_aabb_t *a, pe_aabb_t *b);
pe_aabb_t *pe_aabb_union(pe_aabb_t *res, pe_aabb_t *a, pe_aabb_t *b);
pe_aabb_t *pe_aabb_union_shape(pe_aabb_t *res, pe_aabb_t *a, \
struct pe_shape_t *shape, pe_vec2f_t offset);
float pe_aabb_area(pe_aabb_t *a);
pe_aabb_t *pe_aabb_copy(pe_aabb_t *dest, pe_aabb_t *src);
void pe_aabb_init(pe_aabb_t *aabb, pe_vec2f_t min, \
pe_vec2f_t max, int is_point);

pe_aabb_t *pe_aabb_from_shape(pe_aabb_t *buff, struct pe_shape_t *shape);
char pe_aabb_is_equal(pe_aabb_t *a, pe_aabb_t *b);

#endif /* !PHYSICS_AABB_H */