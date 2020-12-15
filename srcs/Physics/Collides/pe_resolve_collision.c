/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - resolve collision
*/

#include "Physics/physics.h"

static void apply_friction(pe_manifold_t *m, float j, \
pe_vec2f_t relative_velocity)
{
    pe_vec2f_t impulse;
    float normal_vel = pe_vec2f_dot_product(relative_velocity, m->normal);
    pe_vec2f_t tangent = VEC2F_SUB(relative_velocity, \
    VEC2F_MUL1(m->normal, normal_vel));
    float jt;
    float mu = (m->a->fixtures[m->fa]->static_friction + \
    m->b->fixtures[m->fb]->static_friction) * 0.7;

    pe_vec2f_normalize(&tangent);
    jt = -pe_vec2f_dot_product(relative_velocity, tangent);
    jt /= m->a->inv_mass + m->b->inv_mass;
    if (fabsf(jt) < j * mu)
        impulse = VEC2F_MUL1(tangent, jt);
    else
        impulse = VEC2F_MUL1(tangent, - j * \
        (m->a->fixtures[m->fa]->dynamic_friction + \
        m->b->fixtures[m->fb]->dynamic_friction) * 0.7);
    m->a->velocity = VEC2F_SUB(m->a->velocity, \
    VEC2F_MUL1(impulse, m->a->inv_mass));
    m->b->velocity = VEC2F_ADD(m->b->velocity, \
    VEC2F_MUL1(impulse, m->b->inv_mass));
}

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
    apply_friction(m, j, relative_velocity);
}