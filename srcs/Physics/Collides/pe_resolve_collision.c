/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - resolve collision
*/

#include "Physics/physics.h"

void pe_resolve_collision(pe_manifold_t *m)
{
    pe_vec2f_t relative_velocity = {m->b->velocity.x - \
        m->a->velocity.x, m->b->velocity.y - m->a->velocity.y};
    float normal_vel = pe_vec2f_dot_product(relative_velocity, m->normal);
    float e;
    float j;

    if (normal_vel > 0)
        return;
    e = MIN(m->a->fixtures[m->fa]->restitution, \
    m->b->fixtures[m->fb]->restitution);
    j = - (1 + e) * normal_vel;
    j /= m->a->inv_mass + m->b->inv_mass;
    m->a->velocity.x -= (j * m->normal.x) * m->a->inv_mass;
    m->a->velocity.y -= (j * m->normal.y) * m->a->inv_mass;
    m->b->velocity.x += (j * m->normal.x) * m->b->inv_mass;
    m->b->velocity.y += (j * m->normal.y) * m->b->inv_mass;
}