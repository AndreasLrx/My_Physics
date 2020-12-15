/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body mass compute
*/

#include "Physics/physics.h"

void pe_body_compute_mass(pe_body_t *body, float add_mass, char compute_all)
{
    size_t nb_fixtures = my_vector_get_size((size_t *)body->fixtures);

    if (!compute_all) {
        pe_mass_add_mass(&body->mass, add_mass);
        return;
    }
    body->mass.mass = 0;
    for (size_t i = 0; i < nb_fixtures; i++)
        pe_mass_add_mass(&body->mass, add_mass);
}