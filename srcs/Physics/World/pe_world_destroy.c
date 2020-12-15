/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - world destroy
*/

#include "Physics/physics.h"

#include <stdio.h>


void pe_world_destroy(pe_world_t *world)
{
    my_vector_free((size_t **)&world->bodies);
    pe_bin_tree_destroy(world->tree);
    free(world);
}