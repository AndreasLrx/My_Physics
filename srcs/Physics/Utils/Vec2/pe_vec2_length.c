/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - vec2f compute length
*/

#include "Physics/physics.h"
#include <math.h>

float pe_vec2f_length(pe_vec2f_t v)
{
    return sqrtf(pe_vec2f_length_squared(v));
}

float pe_vec2i_length(pe_vec2i_t v)
{
    return sqrtf(pe_vec2i_length_squared(v));
}

float pe_vec2u_length(pe_vec2u_t v)
{
    return sqrtf(pe_vec2u_length_squared(v));
}