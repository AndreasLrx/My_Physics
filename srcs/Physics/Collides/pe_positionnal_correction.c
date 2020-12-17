/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - position correction
*/

#include "Physics/physics.h"

void pe_position_correction(pe_manifold_t *m)
{
    float ratio = (MAX(m->penetration - PE_CORRECTION_SLOP, 0.0f) / \
    (m->af->body->mass.inv_mass + \
    m->bf->body->mass.inv_mass)) * PE_POS_CORRECT_RATIO;
    pe_vec2f_t correction = {ratio * m->normal.x, ratio * m->normal.y};

    pe_body_move(m->af->body, VEC2F_MUL1(correction, \
    -m->af->body->mass.inv_mass));
    pe_body_move(m->bf->body, VEC2F_MUL1(correction, \
    m->bf->body->mass.inv_mass));
}