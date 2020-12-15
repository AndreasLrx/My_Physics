/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body compute aabb
*/

#include "Physics/physics.h"

void pe_body_compute_aabb(pe_body_t *body)
{
    size_t nb_fixture = my_vector_get_size((size_t *)body->fixtures);

    pe_aabb_init(&body->aabb, body->pos, body->pos, 1);
    for (size_t i = 0; i < nb_fixture; i++) {
        pe_aabb_union_shape(&body->aabb, &body->aabb, \
        &body->fixtures[i]->shape, body->pos);
    }
}