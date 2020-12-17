/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body mass compute
*/

#include "Physics/physics.h"

static void pe_body_compute_com(pe_body_t *body)
{
    size_t nb_fixtures = my_vector_get_size((size_t *)body->fixtures);
    pe_vec2f_t com = {0, 0};

    for (size_t i = 0; i < nb_fixtures; i++) {
        pe_shape_compute_mass_center(&body->fixtures[i]->shape);
        com = VEC2F_ADD(com, \
        VEC2F_MUL1(body->fixtures[i]->shape.mass_center, \
        body->fixtures[i]->mass));
    }
    body->mass.center = VEC2F_MUL1(com, body->mass.inv_mass);
}

pe_vec2f_t pe_body_com(pe_body_t *body, int to_world)
{
    pe_mat22_t mat;
    pe_vec2f_t com = body->mass.center;

    pe_mat22_init_from_angle(&mat, body->angle);
    pe_mat22_rotate_point(&mat, &com);
    if (to_world)
        return VEC2F_ADD(com, body->pos);
    return com;
}

void pe_body_compute_mass(pe_body_t *body, float add_mass, char compute_all)
{
    size_t nb_fixtures = my_vector_get_size((size_t *)body->fixtures);

    if (body->body_type == STATIC)
        return;
    body->mass.inertia = 1;
    body->mass.inv_inertia = 1;
    if (!compute_all) {
        pe_mass_add_mass(&body->mass, add_mass);
        pe_body_compute_com(body);
        return;
    }
    body->mass.mass = 0;
    for (size_t i = 0; i < nb_fixtures; i++)
        pe_mass_add_mass(&body->mass, body->fixtures[i]->mass);
    pe_body_compute_com(body);
}