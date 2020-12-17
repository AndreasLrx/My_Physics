/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - update shape area value
*/

#include "Physics/physics.h"

float pe_shape_area_circle(pe_shape_t *shape)
{
    return PE_PI * powf(shape->shape.circle.radius, 2);
}

float pe_shape_area_polygon(pe_shape_t *shape)
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

float pe_shape_calc_area(pe_shape_t *shape)
{
    shape->area = pe_shape_area_table[shape->shape_type](shape);
    return shape->area;
}