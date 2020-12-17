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
    float mu = (m->af->static_friction + m->bf->static_friction) * 0.7;

    pe_vec2f_normalize(&tangent);
    jt = -pe_vec2f_dot_product(relative_velocity, tangent);
    jt /= m->af->body->mass.inv_mass + m->bf->body->mass.inv_mass;
    if (fabsf(jt) < j * mu)
        impulse = VEC2F_MUL1(tangent, jt);
    else
        impulse = VEC2F_MUL1(tangent, - j * \
        (m->af->dynamic_friction + \
        m->bf->dynamic_friction) * 0.7);
    m->af->body->velocity = VEC2F_SUB(m->af->body->velocity, \
    VEC2F_MUL1(impulse, m->af->body->mass.inv_mass));
    m->bf->body->velocity = VEC2F_ADD(m->bf->body->velocity, \
    VEC2F_MUL1(impulse, m->bf->body->mass.inv_mass));
}

void pe_resolve_collision(pe_manifold_t *m)
{
    pe_vec2f_t relative_velocity = VEC2F_SUB(m->bf->body->velocity, \
    m->af->body->velocity);
    float normal_vel = pe_vec2f_dot_product(relative_velocity, m->normal);
    float e;
    float j;

    if (normal_vel > 0)
        return;
    e = MIN(m->af->restitution, m->bf->restitution);
    j = - (1 + e) * normal_vel;
    j /= m->af->body->mass.inv_mass + m->bf->body->mass.inv_mass;
    m->af->body->velocity = VEC2F_SUB(m->af->body->velocity, \
    VEC2F_MUL1(m->normal, j * m->af->body->mass.inv_mass));
    m->bf->body->velocity = VEC2F_ADD(m->bf->body->velocity, \
    VEC2F_MUL1(m->normal, j * m->bf->body->mass.inv_mass));
    apply_friction(m, j, relative_velocity);
}