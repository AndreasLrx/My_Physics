/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - collide fcts btwn circles
*/

#include "Physics/physics.h"

char pe_collide_circle_circle(pe_shape_t *c1, pe_shape_t *c2)
{
    float squared_min_dist = c1->shape.circle.radius + c2->shape.circle.radius;
    float square_dist = powf(c1->pos.x +c2->pos.x, 2) + \
    powf(c1->pos.y + c2->pos.y, 2);

    squared_min_dist *= squared_min_dist;
    return squared_min_dist < square_dist;
}

char pe_manifold_fill_circle_circle(pe_manifold_t *m)
{
    pe_vec2f_t n = VEC2F_SUB(SHAPE_POS(m->bf), SHAPE_POS(m->af));
    float r = m->af->shape.shape.circle.radius + \
    m->bf->shape.shape.circle.radius;
    float d = pe_vec2f_length_squared(n);

    if (d > r * r)
        return 0;
    d = sqrt(d);
    m->nb_contacts = 1;
    if (d != 0) {
        m->penetration = r - d;
        m->normal = VEC2F_MUL1(n, 1 / d);
        m->contacts[0] = VEC2F_ADD(VEC2F_MUL1(n, \
        m->af->shape.shape.circle.radius), SHAPE_POS(m->af));
    } else {
        m->penetration = MAX(m->af->shape.shape.circle.radius, \
        m->bf->shape.shape.circle.radius);
        m->normal = VEC2F(1, 0);
        m->contacts[0] = SHAPE_POS(m->af);
    }
    return 1;
}