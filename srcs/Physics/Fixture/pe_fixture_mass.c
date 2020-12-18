/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - fixture mass
*/

#include "Physics/physics.h"

float pe_fixture_update_mass_datas(pe_fixture_t *fixture)
{
    fixture->mass = pe_shape_compute_mass_datas(\
    &fixture->shape, fixture->density);
    return fixture->mass;
}