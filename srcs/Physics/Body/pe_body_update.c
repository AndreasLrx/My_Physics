/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - update body
*/

#include "Physics/physics.h"

static void pe_body_apply_move(pe_body_t *body, pe_move_t *move, float dt)
{
    switch (move->move_type) {
    case FORCE:
        body->velocity = VEC2F_ADD(body->velocity, \
        VEC2F_MUL1(move->move.force.vec, dt * body->mass));
        break;
    case TORQUE:
        body->angular_velocity += move->move.torque.torque * dt;
        break;
    default:
        break;
    }
}

void pe_body_update(pe_body_t *body, float dt)
{
    size_t nb_moves = my_vector_get_size((size_t *)body->moves);
    pe_vec2f_t move_vec;

    for (size_t i = 0; i < nb_moves; i++) {
        pe_body_apply_move(body, body->moves[i], dt);
    }
    body->velocity = VEC2F_MUL1(body->velocity, \
    CLAMP(1 - (dt * body->linear_damping), 0, 1));
    move_vec = VEC2F_MUL1(body->velocity, dt);
    pe_body_move(body, move_vec);
}

void pe_body_move(pe_body_t *body, pe_vec2f_t move)
{
    body->pos = VEC2F_ADD(body->pos, move);
    body->aabb.min = VEC2F_ADD(body->aabb.min, move);
    body->aabb.max = VEC2F_ADD(body->aabb.max, move);
}