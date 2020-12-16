/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - collision jump table
*/

#include "Physics/physics.h"

const char (*pe_collide_table[2][2])(pe_manifold_t *) = {
    {&pe_manifold_fill_circle_circle, &pe_manifold_fill_circle_polygon}, \
    {&pe_manifold_fill_polygone_circle, &pe_manifold_fill_polygon_polygon}
};