/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - destroy shapes
*/

#include "Physics/physics.h"

void pe_shape_reset(pe_shape_t *shape)
{
    if (shape->shape_type == POLYGON) {
        free(shape->shape.polygon.normals);
        free(shape->shape.polygon.vertices);
    }
}