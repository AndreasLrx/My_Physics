/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - manifold fcts
*/

#include "Physics/physics.h"

void pe_manifold_swap_bodies(pe_manifold_t *m)
{
    pe_fixture_t *tempo = m->af;

    m->af = m->bf;
    m->bf = tempo;
}

void pe_manifold_init(pe_manifold_t *m, float dt, pe_vec2f_t gravity)
{
    pe_body_t *a = m->af->body;
    pe_body_t *b = m->bf->body;
    pe_vec2f_t ra;
    pe_vec2f_t rb;
    pe_vec2f_t rv;

    m->e = MIN(m->af->restitution, m->bf->restitution);
    m->sf = sqrtf(m->af->static_friction * m->bf->static_friction);
    m->df = sqrtf(m->af->dynamic_friction * m->bf->dynamic_friction);
    for (int i = 0; i < m->nb_contacts; i++) {
        ra = VEC2F_SUB(m->contacts[i], pe_body_com(a, 1));
        rb = VEC2F_SUB(m->contacts[i], pe_body_com(b, 1));
        rv = VEC2F_SUB(VEC2F_ADD(b->velocity, \
        pe_vec2f_cross_product_scalar_vec(b->angular_velocity, rb)), \
        VEC2F_SUB(a->velocity, \
        pe_vec2f_cross_product_scalar_vec(a->angular_velocity, ra)));
        if (pe_vec2f_length_squared(rv) < \
            pe_vec2f_length_squared(VEC2F_MUL1(gravity, dt)) + PE_EPSILON)
            m->e = 0.0f;
    }
}