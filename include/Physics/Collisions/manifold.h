/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - collision manifold
*/

#ifndef PHYSICS_MANIFOLD_H
#define PHYSICS_MANIFOLD_H

#include "../Utils/utils.h"

typedef struct pe_manifold_t {
    int fa;
    int fb;
    struct pe_body_t *a;
    struct pe_body_t *b;
    pe_vec2f_t normal;
    float penetration;
} pe_manifold_t;

void pe_manifold_swap_bodies(pe_manifold_t *m);

char pe_collide_circle_circle(pe_shape_t *c1, pe_shape_t *c2);
char pe_collide_aabbs(pe_aabb_t *a, pe_aabb_t *b);

char pe_manifold_fill_aabb_aabb(pe_manifold_t *m);
char pe_manifold_fill_aabb_circle(pe_manifold_t *m);
char pe_manifold_fill_circle_aabb(pe_manifold_t *m);
char pe_manifold_fill_circle_circle(pe_manifold_t *m);

#endif /* !PHYSICS_MANIFOLD_H */