/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - vec2 dot product
*/

#include "Physics/physics.h"

float pe_vec2f_dot_product(pe_vec2f_t v1, pe_vec2f_t v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

int pe_vec2i_dot_product(pe_vec2i_t v1, pe_vec2i_t v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

unsigned int pe_vec2u_dot_product(pe_vec2u_t v1, pe_vec2u_t v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}