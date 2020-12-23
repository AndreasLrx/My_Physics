/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body mass compute
*/

#include "Physics/physics.h"

void pe_body_compute_mass_datas(pe_body_t *body)
{
    size_t nb_fixtures = my_vector_get_size((size_t *)body->fixtures);
    pe_vec2f_t com = {0, 0};

    body->mass.mass = 0;
    body->mass.inertia = 0;
    for (size_t i = 0; i < nb_fixtures; i++) {
        pe_fixture_update_mass_datas(body->fixtures[i]);
        body->mass.mass += body->fixtures[i]->mass;
        body->mass.inertia += body->fixtures[i]->shape.inertia;
        com = VEC2F_ADD(com, \
        VEC2F_MUL1(body->fixtures[i]->shape.mass_center, \
        body->fixtures[i]->mass));
    }
    pe_mass_data_update(&body->mass, body->body_type == STATIC);
    body->mass.center = VEC2F_MUL1(com, body->mass.inv_mass);
    if (body->body_type == STATIC) {
        body->mass.mass = 0;
        body->mass.inv_mass = 0;
        body->mass.inertia = 0;
        body->mass.inv_inertia = 0;
    }
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