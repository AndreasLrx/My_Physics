/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - AABB collides
*/

#include "Physics/physics.h"

char pe_collide_aabbs(pe_aabb_t *a, pe_aabb_t *b)
{
    return (!(a->max.x < b->min.x || a->min.x > b->max.x || \
    a->max.y < b->min.y || a->min.y > b->max.y));
}

char pe_fill_aabb_aabb_manifold(pe_manifold_t *m)
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

static void clamp_circle_to_edge(pe_vec2f_t *closest, pe_vec2f_t *n, \
char *inside, pe_vec2f_t *mid_size)
{
    if (pe_vec2f_cmp(*closest, *n)) {
        *inside = 1;
        if (fabsf(n->x) > fabsf(n->y)) {
            closest->x = (n->x >= 0) ? mid_size->x : -mid_size->x;
        } else {
            closest->y = (n->y >= 0) ? mid_size->y : -mid_size->y;
        }
    }
}

char pe_fill_aabb_circle_manifold(pe_manifold_t *m)
{
    pe_vec2f_t n = VEC2F_SUB(m->b->pos, m->a->pos);
    pe_vec2f_t closest = n;
    pe_vec2f_t mid_size = VEC2F_MUL1(m->a->aabb.size, 0.5);
    pe_vec2f_t normal;
    float d;
    float r = m->b->fixtures[m->fb]->shape.shape.circle.radius;
    char inside = 0;

    closest.x = CLAMP(closest.x, -mid_size.x, mid_size.x);
    closest.y = CLAMP(closest.y, -mid_size.y, mid_size.y);
    clamp_circle_to_edge(&closest, &n, &inside, &mid_size);
    normal = VEC2F_SUB(n, closest);
    d = normal.x * normal.x + normal.y * normal.y;
    if (d > r * r && !inside)
        return 0;
    d = sqrt(d);
    m->penetration = r - d;
    m->normal = VEC2F(normal.x / d, normal.y / d);
    if (inside)
        m->normal = VEC2F_MUL1(normal, -1);
    return 1;
}