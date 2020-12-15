/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - Fixture
*/

#ifndef PHYSICS_FIXTURE_H
#define PHYSICS_FIXTURE_H

#include "../Shapes/shape.h"
#include "../Filter/filter.h"

/*
** Units :
** Density
**    - kg/m²
** Mass
**    - kg
** 
** Factors :
** Friction
**    - [0, 1]
** Restitution
**    - [0, 1]
*/
typedef struct pe_fixture_t {
    pe_shape_t shape;
    float friction;
    float density;
    float restitution;
    pe_filter_t collision_filter;
    char is_sensor;
    float mass;
    struct pe_body_t *body;
} pe_fixture_t;

pe_fixture_t *pe_fixture_init(void);
void pe_fixture_destroy(pe_fixture_t *fixture);

float pe_fixture_update_mass(pe_fixture_t *fixture);

#endif /* !PHYSICS_FIXTURE_H */