/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body mass compute
*/

#include "Physics/physics.h"

void pe_body_compute_mass_inv(pe_body_t *body)
{
    body->inv_mass = \
    (body->mass == 0 || body->body_type == STATIC) ? 0 : 1 / body->mass;
}

void pe_body_compute_mass(pe_body_t *body, float add_mass, char compute_all)
{
    size_t nb_fixtures = my_vector_get_size((size_t *)body->fixtures);

    if (!compute_all) {
        body->mass += add_mass;
        pe_body_compute_mass_inv(body);
        return;
    }
    body->mass = 0;
    for (size_t i = 0; i < nb_fixtures; i++)
        body->mass += pe_fixture_update_mass(body->fixtures[i]);
    pe_body_compute_mass_inv(body);
}