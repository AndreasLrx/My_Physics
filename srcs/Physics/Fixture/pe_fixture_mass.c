/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - fixture mass
*/

#include "Physics/physics.h"

float pe_fixture_update_mass(pe_fixture_t *fixture)
{
    pe_shape_calc_area(&fixture->shape);
    pe_shape_compute_mass_center(&fixture->shape);
    fixture->mass = fixture->density * fixture->shape.area;
    pe_shape_compute_inertia(&fixture->shape, fixture->mass);
    return fixture->mass;
}