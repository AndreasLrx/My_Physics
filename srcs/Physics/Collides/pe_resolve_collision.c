/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - resolve collision
*/

#include "Physics/physics.h"

static pe_vec2f_t get_relative_contact_velocity(pe_vec2f_t *ra, \
pe_vec2f_t *rb, int i, pe_manifold_t *m)
{
    pe_body_t *a = m->af->body;
    pe_body_t *b = m->bf->body;

    *ra = VEC2F_SUB(m->contacts[i], pe_body_com(a, 1));
    *rb = VEC2F_SUB(m->contacts[i], pe_body_com(b, 1));
    return VEC2F_SUB(VEC2F_ADD(b->velocity, \
        pe_vec2f_cross_product_scalar_vec(b->angular_velocity, *rb)), \
        VEC2F_SUB(a->velocity, \
        pe_vec2f_cross_product_scalar_vec(a->angular_velocity, *ra)));
}

void pe_resolve_collision_rotate(pe_manifold_t *m)
{
    pe_body_t *a = m->af->body;
    pe_body_t *b = m->bf->body;
    pe_vec2f_t ra;
    pe_vec2f_t rb;
    float contact_velocity;
    pe_vec2f_t impulse;

    for (int i = 0; i < m->nb_contacts; ++i) {
        contact_velocity = pe_vec2f_dot_product(\
        get_relative_contact_velocity(&ra, &rb, i, m), m->normal);
        if (contact_velocity > 0)
            return;
        impulse = VEC2F_MUL1(m->normal, (-(1 + m->e) * contact_velocity) / \
        ((a->mass.inv_mass + b->mass.inv_mass + powf(\
        pe_vec2f_cross_product_vec_vec(ra, m->normal), 2) * \
        a->mass.inv_inertia + powf(\
        pe_vec2f_cross_product_vec_vec(rb, m->normal), 2) * \
        b->mass.inv_inertia) * m->nb_contacts));
        pe_body_apply_impulse_on_point(a, pe_vec2f_opposite(impulse), ra);
        pe_body_apply_impulse_on_point(b, impulse, rb);
    }
}