/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - update body
*/

#include "Physics/physics.h"

void pe_body_update(pe_body_t *body, float dt)
{
    if (body->body_type == STATIC)
        return;
    pe_body_move(body, VEC2F_MUL1(body->velocity, dt));
    pe_body_rotate(body, body->angular_velocity * dt);
    pe_body_integrate_forces(body, dt);
}