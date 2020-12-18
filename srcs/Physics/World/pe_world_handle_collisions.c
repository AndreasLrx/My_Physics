/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - handle collisions
*/

#include "Physics/physics.h"

void pe_world_handle_collisions_for_body(pe_world_t *world, pe_body_t *body, pe_manifold_t **contact_vec)
{
    int parent_box_id = pe_collide_get_collide_aabb_id(world->tree, body);

    pe_collide_body_from_parent(world->tree, parent_box_id, body, contact_vec);
    //world->tree->nodes[body->id]->tested = 1;
}