/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - aabb from shape
*/

#include "Physics/physics.h"

static void from_circle(pe_aabb_t *box, pe_shape_t *shape)
{
    box->min = VEC2F_SUB1(shape->pos, shape->shape.circle.radius);
    box->max = VEC2F_ADD1(shape->pos, shape->shape.circle.radius);
}

static void from_polygon(pe_aabb_t *box, pe_shape_t *shape)
{
    int nb_vertices = shape->shape.polygon.count;

    box->min = \
    (nb_vertices <= 0) ? shape->pos : shape->shape.polygon.vertices[0];
    box->max = \
    (nb_vertices <= 0) ? shape->pos : shape->shape.polygon.vertices[0];
    for (int i = 0; i < nb_vertices; i++) {
        if (shape->shape.polygon.vertices[i].x < box->min.x)
            box->min.x = shape->shape.polygon.vertices[i].x;
        if (shape->shape.polygon.vertices[i].x > box->max.x)
            box->max.x = shape->shape.polygon.vertices[i].x;
        if (shape->shape.polygon.vertices[i].y < box->min.y)
            box->min.y = shape->shape.polygon.vertices[i].y;
        if (shape->shape.polygon.vertices[i].y > box->max.y)
            box->max.y = shape->shape.polygon.vertices[i].y;
    }
    box->min = VEC2F_ADD(box->min, shape->pos);
    box->max = VEC2F_ADD(box->max, shape->pos);
}

pe_aabb_t *pe_aabb_from_shape(pe_aabb_t *buff, pe_shape_t *shape)
{
    pe_aabb_t *box = buff;

    if (box == NULL)
        box = malloc(sizeof(pe_aabb_t));
    switch (shape->shape_type) {
    case CIRCLE:
        from_circle(box, shape);
        break;
    case POLYGON:
        from_polygon(box, shape);
        break;
    default:
        break;
    }
    box->size = VEC2F_SUB(box->max, box->min);
    return box;
}