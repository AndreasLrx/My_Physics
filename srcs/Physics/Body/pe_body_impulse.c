/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body impulse
*/

#include "Physics/physics.h"

void pe_body_apply_impulse_on_point(pe_body_t *body, \
pe_vec2f_t impulse, pe_vec2f_t contact_vec)
{
    body->velocity = VEC2F_ADD(body->velocity, \
    VEC2F_MUL1(impulse, body->mass.inv_mass));
    body->angular_velocity += body->mass.inv_inertia * \
    pe_vec2f_cross_product_vec_vec(contact_vec, impulse);
}

void pe_body_apply_impulse(pe_body_t *body, pe_vec2f_t impulse)
{
    body->velocity = VEC2F_SUB(body->velocity, \
    VEC2F_MUL1(impulse, body->mass.inv_mass));
}