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

void pe_resolve_collision_rotate(pe_manifold_t *m)
{
    pe_body_t *a = m->af->body;
    pe_body_t *b = m->bf->body;
    pe_vec2f_t ra;
    pe_vec2f_t rb;
    pe_vec2f_t rv;
    float contact_velocity;
    float ra_cross_n;
    float rb_cross_n;
    float inv_mass_sum;
    float j;
    float jt;
    float e = MIN(m->af->restitution, m->bf->restitution);
    pe_vec2f_t impulse;
    pe_vec2f_t t;
    pe_vec2f_t tangent_impulse;

    for (int i = 0; i < m->nb_contacts; ++i) {
        ra = VEC2F_SUB(m->contacts[i], pe_body_com(a, 1));
        rb = VEC2F_SUB(m->contacts[i], pe_body_com(b, 1));
        rv = VEC2F_SUB(VEC2F_ADD(b->velocity, pe_vec2f_cross_product_scalar_vec(b->angular_velocity, rb)), \
        VEC2F_SUB(a->velocity, pe_vec2f_cross_product_scalar_vec(a->angular_velocity, ra)));
        contact_velocity = pe_vec2f_dot_product(rv, m->normal);
        if (contact_velocity > 0)
            return;
        ra_cross_n = pe_vec2f_cross_product_vec_vec(ra, m->normal);
        rb_cross_n = pe_vec2f_cross_product_vec_vec(rb, m->normal);
        inv_mass_sum = a->mass.inv_mass + b->mass.inv_mass + powf(ra_cross_n, 2) * a->mass.inv_inertia + powf(rb_cross_n, 2) * b->mass.inv_inertia;
        j = - (1 + e) * contact_velocity;
        j /= inv_mass_sum;
        j /= (float)m->nb_contacts;
        impulse = VEC2F_MUL1(m->normal, j);
        pe_body_apply_impulse(a, pe_vec2f_opposite(impulse), ra);
        pe_body_apply_impulse(b, impulse, rb);

        /*rv = VEC2F_SUB(VEC2F_ADD(b->velocity, pe_vec2f_cross_product_scalar_vec(b->angular_velocity, rb)), \
        VEC2F_SUB(a->velocity, pe_vec2f_cross_product_scalar_vec(a->angular_velocity, ra)));*/
        t = VEC2F_SUB(rv, VEC2F_MUL1(m->normal, pe_vec2f_dot_product(rv, m->normal)));
        pe_vec2f_normalize(&t);
        jt = -pe_vec2f_dot_product(rv, t);
        jt /= inv_mass_sum;
        jt /= (float)m->nb_contacts;
        if(fabsf(jt) <= 0.0001f)
            return;
        if(fabsf(jt) < j * (m->af->static_friction + m->bf->static_friction) * 0.7)
            tangent_impulse = VEC2F_MUL1(t, jt);
        else
            tangent_impulse = VEC2F_MUL1(t, -j * (m->af->dynamic_friction + m->bf->dynamic_friction) * 0.7);

        pe_body_apply_impulse(a, pe_vec2f_opposite(tangent_impulse), ra );
        pe_body_apply_impulse(b, tangent_impulse, rb );
    }
}