/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - manifold fcts
*/

#include "Physics/physics.h"

void pe_manifold_swap_bodies(pe_manifold_t *m)
{
    pe_fixture_t *tempo = m->af;

    m->af = m->bf;
    m->bf = tempo;
}