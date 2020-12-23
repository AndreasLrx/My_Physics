/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - update body
*/

#include "Physics/physics.h"

void pe_body_update(pe_body_t *body, float dt)
{
    if (body->body_type == STATIC || !body->is_awake)
        return;
    pe_body_move(body, VEC2F_MUL1(body->velocity, dt));
    pe_body_rotate(body, body->angular_velocity * dt);
    pe_body_integrate_forces(body, dt);
}

void pe_body_set_awake(pe_body_t *body, char awake)
{
    if (awake || !body->can_sleep || 1) {
        body->is_awake = awake;
        body->motion = PE_SLEEP_EPSILON * 2.0f;
    } else {
        body->is_awake = awake;
        body->velocity = VEC2F(0, 0);
        body->angular_velocity = 0;
        pe_body_clear_forces(body, 1, 1, 1);
    }
}

void pe_body_try_sleep(pe_body_t *body, float dt)
{
    float bias = powf(0.8, dt);
    float current_motion = \
    pe_vec2f_dot_product(body->velocity, body->velocity) + \
    powf(body->angular_velocity, 2);

    body->motion = bias * body->motion + (1 - bias) * current_motion;
    if (body->motion > PE_SLEEP_EPSILON * 10)
        body->motion = PE_SLEEP_EPSILON * 10;
    if (body->motion < PE_SLEEP_EPSILON) {
        pe_body_set_awake(body, 0);
    }
}