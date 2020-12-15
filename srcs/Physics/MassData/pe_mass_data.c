/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - Compute inverse
*/

#include "Physics/physics.h"

void pe_mass_data_init(pe_mass_data_t *mass, float init_mass, \
float init_inertia, char static_body)
{
    mass->mass = init_mass;
    mass->inertia = init_inertia;
    pe_mass_data_update(mass, static_body);
}

void pe_mass_add_mass(pe_mass_data_t *mass, float value)
{
    mass->mass += value;
    pe_mass_data_update(mass, 0);
}

void pe_mass_add_inertia(pe_mass_data_t *mass, float value)
{
    mass->inertia += value;
    pe_mass_data_update(mass, 0);
}

void pe_mass_data_update(pe_mass_data_t *mass, char static_body)
{
    mass->inv_mass = \
    (static_body || mass->mass == 0) ? 0 : 1 / mass->mass;
    mass->inv_inertia = \
    (static_body || mass->inertia == 0) ? 0 : 1 / mass->inertia;
}