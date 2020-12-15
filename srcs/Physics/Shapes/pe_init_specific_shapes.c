/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - specific init
*/

#include "Physics/physics.h"

void pe_shape_init_circle(pe_shape_t *shape, float radius, pe_vec2f_t pos)
{
    shape->pos = pos;
    shape->shape_type = CIRCLE;
    shape->shape.circle.radius = radius;
    pe_shape_calc_area(shape);
}

void pe_shape_init_rect(pe_shape_t *shape, pe_vec2f_t pos, pe_vec2f_t size)
{
    pe_vec2f_t mid_size = VEC2F_MUL1(size, 0.5);

    shape->pos = pos;
    shape->shape_type = POLYGON;
    shape->shape.polygon.count = 4;
    shape->shape.polygon.vertices = malloc(sizeof(pe_vec2f_t) * 4);
    shape->shape.polygon.vertices[0] = VEC2F_SUB(pos, mid_size);
    for (int i = 1; i < 4; i++)
        shape->shape.polygon.vertices[i] = shape->shape.polygon.vertices[0];
    shape->shape.polygon.vertices[1].x += size.x;
    shape->shape.polygon.vertices[2].x += size.x;
    shape->shape.polygon.vertices[2].y += size.y;
    shape->shape.polygon.vertices[3].y += size.y;
    pe_shape_calc_area(shape);
}

void pe_shape_init_default(pe_shape_t *shape)
{
    pe_shape_init_rect(shape, (pe_vec2f_t){0, 0}, (pe_vec2f_t){1, 1});
}