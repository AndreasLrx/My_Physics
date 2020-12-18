/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body move
*/

#include "Physics/physics.h"

void pe_body_move(pe_body_t *body, pe_vec2f_t move)
{
    body->pos = VEC2F_ADD(body->pos, move);
    body->aabb.min = VEC2F_ADD(body->aabb.min, move);
    body->aabb.max = VEC2F_ADD(body->aabb.max, move);
}

void pe_body_set_pos(pe_body_t *body, pe_vec2f_t pos)
{
    pe_vec2f_t diff = VEC2F_SUB(pos, body->pos);

    pe_body_move(body, diff);
}