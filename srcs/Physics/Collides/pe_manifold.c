/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - manifold fcts
*/

#include "Physics/physics.h"

void pe_manifold_swap_bodies(pe_manifold_t *m)
{
    pe_body_t *tempo_b = m->a;
    int tempo_f = m->fa;

    m->a = m->b;
    m->fa = m->fb;
    m->b = tempo_b;
    m->fb = tempo_f;
}