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
    (m->a->inv_mass + m->b->inv_mass)) * PE_POS_CORRECT_RATIO;
    pe_vec2f_t correction = {ratio * m->normal.x, ratio * m->normal.y};

    pe_body_move(m->a, VEC2F_MUL1(correction, -m->a->inv_mass));
    pe_body_move(m->b, VEC2F_MUL1(correction, m->b->inv_mass));
}