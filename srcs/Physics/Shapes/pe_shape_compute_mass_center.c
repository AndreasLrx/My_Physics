/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - compute mass center
*/

#include "Physics/physics.h"

static pe_vec2f_t compute_polygon_com(pe_vec2f_t *vertices, int count)
{
    float twice_area = 0;
    pe_vec2f_t pos = {0, 0};
    pe_vec2f_t p1;
    pe_vec2f_t p2;
    float factor;

    for (int i = 0; i < count; i++) {
        p1 = vertices[i];
        p2 = vertices[(((i + 1) < count) ? i + 1 : 0)];
        factor = p1.x * p2.y - p2.x * p1.y;
        twice_area += factor;
        pos = VEC2F_ADD(pos, VEC2F_MUL1(VEC2F_ADD(p1, p2), factor));
    }
    factor = 1 / (twice_area * 3);
    return VEC2F_MUL1(pos, factor);
}

pe_vec2f_t *pe_shape_compute_mass_center(pe_shape_t *shape)
{
    switch (shape->shape_type) {
    case CIRCLE:
        shape->mass_center = shape->pos;
        break;
    case POLYGON:
        shape->mass_center = \
        compute_polygon_com(shape->shape.polygon.vertices, \
        shape->shape.polygon.count);
        break;
    default:
        break;
    }
    return &shape->mass_center;
}