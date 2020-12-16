/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - vec2f cross product
*/

#include "Physics/physics.h"

float pe_vec2f_cross_product_vec_vec(pe_vec2f_t v1, pe_vec2f_t v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

pe_vec2f_t pe_vec2f_cross_product_vec_scalar(pe_vec2f_t v, float scalar)
{
    return VEC2F(scalar * v.y, -scalar * v.x);
}

pe_vec2f_t pe_vec2f_cross_product_scalar_vec(float scalar, pe_vec2f_t v)
{
    return VEC2F(-scalar * v.y, scalar * v.x);
}