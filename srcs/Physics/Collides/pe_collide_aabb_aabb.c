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

char pe_manifold_fill_aabb_aabb(pe_manifold_t *m)
{
    pe_vec2f_t delta = VEC2F_SUB(m->b->pos, m->a->pos);
    float x_overlap = m->a->aabb.size.x / 2.f + \
    m->b->aabb.size.x / 2.f - fabsf(delta.x);
    float y_overlap = (x_overlap > 0) ? m->a->aabb.size.y / 2.f + \
m->b->aabb.size.y / 2.f - fabsf(delta.y) : -1;

    if (y_overlap <= 0)
        return 0;
    if (x_overlap < y_overlap) {
        m->normal = VEC2F((delta.x < 0) ? -1 : 1, 0);
        m->penetration = x_overlap;
    } else {
        m->normal = VEC2F(0, (delta.y < 0) ? -1 : 1);
        m->penetration = y_overlap;
    }
    return 1;
}