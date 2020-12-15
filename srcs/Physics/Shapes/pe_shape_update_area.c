/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - update shape area value
*/

#include "Physics/physics.h"

static void circle_area_calc(pe_shape_t *shape)
{
    shape->area = PE_PI * powf(shape->shape.circle.radius, 2);
}

static void polygon_area_calc(pe_shape_t *shape)
{
    pe_vec2f_t min = shape->shape.polygon.vertices[0];
    pe_vec2f_t max = shape->shape.polygon.vertices[0];

    for (int i = 0; i < shape->shape.polygon.count; i++) {
        if (min.x > shape->shape.polygon.vertices[i].x)
            min.x = shape->shape.polygon.vertices[i].x;
        if (max.x < shape->shape.polygon.vertices[i].x)
            max.x = shape->shape.polygon.vertices[i].x;
        if (min.y > shape->shape.polygon.vertices[i].y)
            min.y = shape->shape.polygon.vertices[i].y;
        if (max.y < shape->shape.polygon.vertices[i].y)
            max.y = shape->shape.polygon.vertices[i].y;
    }
    shape->area = (max.x - min.x) * (max.y - min.y);
}

float pe_shape_calc_area(pe_shape_t *shape)
{
    switch (shape->shape_type) {
    case CIRCLE:
        circle_area_calc(shape);
        break;
    case POLYGON:
        polygon_area_calc(shape);
        break;
    default:
        break;
    }
    return shape->area;
}