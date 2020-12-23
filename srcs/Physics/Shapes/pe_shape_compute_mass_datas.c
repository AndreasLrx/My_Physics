/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - compute mass center
*/

#include "Physics/physics.h"

static float compute_cirle_mass_data(pe_shape_t *shape, \
pe_circle_shape_t *circle, float density)
{
    shape->mass_center = shape->pos;
    shape->area = PE_PI * pow(circle->radius, 2);
    shape->inertia = (PE_PI / 4.0f) * powf(circle->radius, 4) * density;
    return shape->area * density;
}

static float compute_polygon_mass_data(pe_shape_t *shape, \
pe_polygon_shape_t *poly, float density)
{
    pe_vec2f_t v1;
    pe_vec2f_t v2;
    float cross;

    shape->inertia = 0.0f;
    shape->area = 0.0f;
    shape->mass_center = VEC2F(0, 0);
    for (int i = 0; i < poly->count; i++) {
        v1 = poly->vertices[i];
        v2 = poly->vertices[(i + 1 < poly->count) ? i + 1 : 0];
        cross = pe_vec2f_cross_product_vec_vec(v1, v2);
        shape->area += cross * 0.5f;
        shape->mass_center = VEC2F_ADD(shape->mass_center, \
        VEC2F_MUL1(VEC2F_ADD(v1, v2), 1 / 3.f * cross * 0.5f));
        shape->inertia += (0.25f * 1 / 3.f * cross) * \
        (pe_vec2f_dot_product(v1, v1) + \
        pe_vec2f_dot_product(v2, v2) + pe_vec2f_dot_product(v1, v2));
    }
    shape->mass_center = VEC2F_MUL1(shape->mass_center, 1 / shape->area);
    shape->inertia *= density;
    return density * shape->area;
}

float pe_shape_compute_mass_datas(pe_shape_t *shape, float density)
{
    switch (shape->shape_type) {
    case CIRCLE:
        return compute_cirle_mass_data(shape, &shape->shape.circle, density);
    case POLYGON:
        return compute_polygon_mass_data(shape, &shape->shape.polygon, density);
    default:
        return 0;
    }
}