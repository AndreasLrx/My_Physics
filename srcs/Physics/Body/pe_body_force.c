/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - force on bodies
*/

#include "Physics/physics.h"

void pe_body_clear_force(pe_body_t *body)
{
    body->force = VEC2F(0, 0);
}

void pe_body_apply_force(pe_body_t *body, pe_vec2f_t force)
{
    body->force = VEC2F_ADD(body->force, force);
}