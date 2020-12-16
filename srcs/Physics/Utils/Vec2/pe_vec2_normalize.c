/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - normalize vectors
*/

#include "Physics/physics.h"

static float fisqrt(float number)
{
    float x2 = number * 0.5f;
    float threehalfs = 1.5f;
    union {
        float f;
        uint32_t i;
    } conv = {.f = number};

    conv.i = 0x5f3759df - (conv.i >> 1);
    conv.f *= threehalfs - (x2 * conv.f * conv.f);
    return conv.f;
}

pe_vec2f_t *pe_vec2f_normalize(pe_vec2f_t *v)
{
    float inv_sqrt = fisqrt(pe_vec2f_length_squared(*v));

    v->x *= inv_sqrt;
    v->y *= inv_sqrt;
    return v;
}

pe_vec2i_t *pe_vec2i_normalize(pe_vec2i_t *v)
{
    float inv_sqrt = fisqrt(pe_vec2i_length_squared(*v));

    v->x *= inv_sqrt;
    v->y *= inv_sqrt;
    return v;
}

pe_vec2u_t *pe_vec2u_normalize(pe_vec2u_t *v)
{
    float inv_sqrt = fisqrt(pe_vec2u_length_squared(*v));

    v->x *= inv_sqrt;
    v->y *= inv_sqrt;
    return v;
}