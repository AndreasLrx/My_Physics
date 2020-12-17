/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - aabb from shape
*/

#include <float.h>
#include "Physics/physics.h"

static void from_circle(pe_aabb_t *box, pe_shape_t *shape)
{
    box->min = VEC2F_SUB1(shape->pos, shape->shape.circle.radius);
    box->max = VEC2F_ADD1(shape->pos, shape->shape.circle.radius);
}

static void from_polygon(pe_aabb_t *box, pe_shape_t *shape)
{
    int nb_vertices = shape->shape.polygon.count;
    pe_vec2f_t vertice;

    box->min = (nb_vertices <= 0) ? shape->pos : VEC2F(FLT_MAX, FLT_MAX);
    box->max = (nb_vertices <= 0) ? shape->pos : VEC2F(FLT_MIN, FLT_MIN);
    for (int i = 0; i < nb_vertices; i++) {
        vertice = VEC2F_ADD(shape->shape.polygon.vertices[i], shape->pos);
        pe_mat22_rotate_point(&shape->mat_rot, &vertice);
        if (vertice.x < box->min.x)
            box->min.x = vertice.x;
        if (vertice.x > box->max.x)
            box->max.x = vertice.x;
        if (vertice.y < box->min.y)
            box->min.y = vertice.y;
        if (vertice.y > box->max.y)
            box->max.y = vertice.y;
    }
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