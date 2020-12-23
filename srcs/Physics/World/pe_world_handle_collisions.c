/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - handle collisions
*/

#include "Physics/physics.h"

void pe_world_handle_collisions_for_body(pe_world_t *world, pe_body_t *body)
{
    int parent_box_id = pe_collide_get_collide_aabb_id(world->tree, body);

    pe_collide_body_from_parent(world->tree, parent_box_id, body);
}