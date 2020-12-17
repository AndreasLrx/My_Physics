/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - set body angle
*/

#include "Physics/physics.h"

void pe_body_set_angle(pe_body_t *body, float rad_angle)
{
    size_t nb_fixtures = my_vector_get_size((size_t *)body->fixtures);

    body->angle = rad_angle;
    for (size_t i = 0; i < nb_fixtures; i++) {
        if (body->fixtures[i]->shape.shape_type == POLYGON)
            pe_mat22_init_from_angle(\
            &body->fixtures[i]->shape.mat_rot, rad_angle);
    }
}

void pe_body_rotate(pe_body_t *body, float rad_angle)
{
    pe_body_set_angle(body, body->angle + rad_angle);
    pe_body_compute_aabb(body);
}