/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - fixture mass
*/

#include "Physics/physics.h"

float pe_fixture_update_mass(pe_fixture_t *fixture)
{
    fixture->mass = fixture->density * fixture->shape.area;
    return fixture->mass;
}