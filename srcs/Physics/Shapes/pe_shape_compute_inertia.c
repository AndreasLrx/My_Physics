/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - update shape inertia value
*/

#include "Physics/physics.h"

float pe_shape_inertia_circle(pe_shape_t *shape, float fixture_mass)
{
    return fixture_mass * powf(shape->shape.circle.radius, 2);
}

float pe_shape_inertia_polygon(pe_shape_t *shape)
{
    float area = 0;
    int j = shape->shape.polygon.count - 1;
    pe_vec2f_t v1;
    pe_vec2f_t v2;

    for (int i = 0; i < shape->shape.polygon.count; i++) {
        v1 = shape->shape.polygon.vertices[j];
        v2 = shape->shape.polygon.vertices[i];
        area += (v1.x + v2.x) * (v1.y - v2.y);
        j = i;
    }
    return fabsf(area / 2.0);
}

float pe_shape_compute_inertia(pe_shape_t *shape, float fixture_mass)
{
    if (shape->shape_type == CIRCLE)
        shape->inertia = pe_shape_inertia_circle(shape, fixture_mass);
    else
        shape->inertia = 1;
    return shape->inertia;
}