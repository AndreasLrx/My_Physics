/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - circle collisions
*/

#include "Physics/physics.h"

char pe_collide_circles(pe_shape_t *c1, pe_shape_t *c2)
{
    float squared_min_dist = c1->shape.circle.radius + c2->shape.circle.radius;
    float square_dist = powf(c1->pos.x +c2->pos.x, 2) + \
    powf(c1->pos.y + c2->pos.y, 2);

    squared_min_dist *= squared_min_dist;
    return squared_min_dist < square_dist;
}

char pe_fill_circle_circle_manifold(pe_manifold_t *m)
{
    pe_vec2f_t n = VEC2F_SUB(m->b->pos, m->a->pos);
    float r = m->a->fixtures[m->fa]->shape.shape.circle.radius + \
    m->b->fixtures[m->fb]->shape.shape.circle.radius;
    float d = n.x * n.x + n.y * n.y;

    if (d > r * r)
        return 0;
    d = sqrt(d);
    if (d != 0) {
        m->penetration = r - d;
        m->normal = VEC2F(n.x / d, n.y / d);
        return 1;
    } else {
        m->penetration = MAX(m->a->fixtures[m->fa]->shape.shape.circle.radius, \
        m->b->fixtures[m->fb]->shape.shape.circle.radius);
        m->normal = VEC2F(1, 0);
        return 1;
    }
}