/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - force on bodies
*/

#include "Physics/physics.h"

void pe_body_clear_forces(pe_body_t *body, int torque, int force, int all)
{
    if (all || force)
        body->force = VEC2F(0, 0);
    if (all || torque)
        body->torque = 0;
}

void pe_body_add_force(pe_body_t *body, pe_vec2f_t force)
{
    body->force = VEC2F_ADD(body->force, force);
}

void pe_body_add_torque(pe_body_t *body, float torque)
{
    body->torque += torque;
}

void pe_body_integrate_forces(pe_body_t *body, float dt)
{
    if (body->body_type == STATIC)
        return;
    body->velocity = VEC2F_MUL1(VEC2F_ADD(body->velocity, \
    VEC2F_MUL1(body->force, 0.5 * dt * body->mass.inv_mass)), \
    CLAMP(1 - (dt * body->linear_damping * 0.5f), 0, 1));
    body->angular_velocity += 0.5f * dt * body->torque * body->mass.inv_inertia;
    body->angular_velocity *= powf(0.1, dt);
}