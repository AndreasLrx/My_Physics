/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - polygone - circle collision
*/

#include "Physics/physics.h"

char pe_manifold_fill_polygone_circle(pe_manifold_t *m)
{
    char res;

    pe_manifold_swap_bodies(m);
    res = pe_manifold_fill_circle_polygon(m);
    return res;
}