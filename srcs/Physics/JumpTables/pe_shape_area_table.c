/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - shape area jump table
*/

#include "Physics/physics.h"

const float (*pe_shape_area_table[2])(struct pe_shape_t *) = {
    &pe_shape_area_circle,
    &pe_shape_area_polygon
};