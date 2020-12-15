/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - world add items
*/

#include "Physics/physics.h"

int pe_world_add_body(pe_world_t *world, pe_body_t *body)
{
    pe_body_compute_aabb(body);
    pe_bin_tree_insert_body(world->tree, body);
    my_vector_push((size_t **)&world->bodies, (size_t)body);
    return 1;
}