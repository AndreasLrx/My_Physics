/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - aabb area
*/

#include "Physics/Shapes/aabb_shape.h"

float pe_aabb_area(pe_aabb_t *box)
{
    return box->size.x * box->size.y;
}