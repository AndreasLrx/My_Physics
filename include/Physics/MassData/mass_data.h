/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - mass data
*/

#ifndef PHYSICS_MASS_DATA_H
#define PHYSICS_MASS_DATA_H

typedef struct pe_mass_data_t {
    float mass;
    float inv_mass;
    float inertia;
    float inv_inertia;
} pe_mass_data_t;

#endif /* !PHYSICS_MASS_DATA_H */