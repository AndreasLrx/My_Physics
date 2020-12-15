/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - compute length squared of vec2
*/

#include "Physics/physics.h"

float pe_vec2f_length_squared(pe_vec2f_t v)
{
    return v.x * v.x + v.y * v.y;
}

int pe_vec2i_length_squared(pe_vec2i_t v)
{
    return v.x * v.x + v.y * v.y;
}

unsigned int pe_vec2u_length_squared(pe_vec2u_t v)
{
    return v.x * v.x + v.y * v.y;
}