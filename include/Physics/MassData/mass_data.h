/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - mass data
*/

#ifndef PHYSICS_MASS_DATA_H
#define PHYSICS_MASS_DATA_H

#include "../Utils/utils.h"

typedef struct pe_mass_data_t {
    pe_vec2f_t center;
    float mass;
    float inv_mass;
    float inertia;
    float inv_inertia;
} pe_mass_data_t;

void pe_mass_data_init(pe_mass_data_t *mass, float init_mass, \
float init_inertia, char static_body);

void pe_mass_add_mass(pe_mass_data_t *mass, float value);
void pe_mass_add_inertia(pe_mass_data_t *mass, float value);

void pe_mass_data_update(pe_mass_data_t *mass, char static_body);

#endif /* !PHYSICS_MASS_DATA_H */