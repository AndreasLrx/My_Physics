/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - force on bodies
*/

#include "Physics/physics.h"

void pe_body_apply_impulse(pe_body_t *body, \
pe_vec2f_t impulse, pe_vec2f_t point)
{
    body->velocity = VEC2F_ADD(body->velocity, \
    VEC2F_MUL1(impulse, body->mass.inv_mass));
    body->angular_velocity += body->mass.inv_inertia * \
    pe_vec2f_cross_product_vec_vec(point, impulse);
}

void pe_body_clear_force(pe_body_t *body)
{
    body->force = VEC2F(0, 0);
    body->torque = 0;
}

void pe_body_apply_force(pe_body_t *body, pe_vec2f_t force)
{
    body->force = VEC2F_ADD(body->force, force);
}