/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - update body
*/

#include "Physics/physics.h"

void pe_body_update(pe_body_t *body, float dt)
{
    pe_vec2f_t move_vec;

    body->velocity = VEC2F_MUL1(VEC2F_ADD(body->velocity, \
    VEC2F_MUL1(body->force, dt * body->mass.mass)), \
    CLAMP(1 - (dt * body->linear_damping), 0, 1));
    move_vec = VEC2F_MUL1(body->velocity, dt);
    pe_body_move(body, move_vec);
    pe_body_clear_force(body);
    body->angular_velocity += dt * body->torque * body->mass.inertia;
    body->angular_velocity *= CLAMP(1 - (dt * body->angular_damping), 0, 1);
    pe_body_rotate(body, body->angular_velocity * dt);
}

void pe_body_move(pe_body_t *body, pe_vec2f_t move)
{
    body->pos = VEC2F_ADD(body->pos, move);
    body->aabb.min = VEC2F_ADD(body->aabb.min, move);
    body->aabb.max = VEC2F_ADD(body->aabb.max, move);
}