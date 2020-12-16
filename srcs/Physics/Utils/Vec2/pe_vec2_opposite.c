/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - Vec2 opposite
*/

#include "Physics/physics.h"

pe_vec2f_t pe_vec2f_opposite(pe_vec2f_t v)
{
    return pe_vec2f_operate((pe_vec2f_t){0, 0}, v, SUBSTRACT);
}

pe_vec2i_t pe_vec2i_opposite(pe_vec2i_t v)
{
    return pe_vec2i_operate((pe_vec2i_t){0, 0}, v, SUBSTRACT);
}

pe_vec2u_t pe_vec2u_opposite(pe_vec2u_t v)
{
    return pe_vec2u_operate((pe_vec2u_t){0, 0}, v, SUBSTRACT);
}