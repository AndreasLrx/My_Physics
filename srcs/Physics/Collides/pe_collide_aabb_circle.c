/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - collide aabb circle fcts
*/

#include "Physics/physics.h"

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

char pe_manifold_fill_aabb_circle(pe_manifold_t *m)
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

char pe_manifold_fill_circle_aabb(pe_manifold_t *m)
{
    char res;

    pe_manifold_swap_bodies(m);
    res = pe_manifold_fill_aabb_circle(m);
    return res;
}