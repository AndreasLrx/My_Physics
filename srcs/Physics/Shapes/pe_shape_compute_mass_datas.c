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
    float mass = 0.0;
    pe_vec2f_t step_center = {0.0, 0.0};
    int prev_vertex = poly->count - 1;
    pe_vec2f_t v1;
    pe_vec2f_t v2;
    float step_values[3];

    shape->inertia = 0.0f;
    shape->area = 0.0f;
    shape->mass_center = VEC2F(0, 0);
    for (int i = 0; i < poly->count; i++) {
        v1 = poly->vertices[prev_vertex];
        v2 = poly->vertices[i];
        step_values[0] = pe_vec2f_cross_product_vec_vec(v1, v2) / 2.f;
        step_values[1] = density * step_values[0];
        step_center = VEC2F_MUL1(VEC2F(v1.x + v2.x, v1.y + v2.y), 1/3.f);
        step_values[2] = step_values[1] / (6 * (pe_vec2f_dot_product(v1, v1) + \
        pe_vec2f_dot_product(v2, v2) + pe_vec2f_dot_product(v1, v2)));
        shape->area += step_values[0];
        shape->mass_center = VEC2F_MUL1(VEC2F_ADD(\
        VEC2F_MUL1(shape->mass_center, mass), \
        VEC2F_MUL1(step_center, step_values[1])), 1 / (mass + step_values[1]));
        mass += step_values[1];
        shape->inertia += step_values[2];
        prev_vertex = i;
    }
    shape->inertia -= mass * \
    pe_vec2f_dot_product(shape->mass_center, shape->mass_center);
    shape->inertia /= 2.f;
    return mass;
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