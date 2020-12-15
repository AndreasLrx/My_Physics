/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - update world
*/

#include "Physics/physics.h"

void pe_world_update(pe_world_t *world, float dt)
{
    float dt_sec = dt / 1000.f;
    size_t nb_body = my_vector_get_size((size_t *)world->bodies);

    for (size_t i = 0; i < nb_body; i++) {
        world->tree->nodes[world->bodies[i]->id]->tested = 0;
    }
    for (size_t i = 0; i < nb_body; i++) {
        if (world->bodies[i]->body_type != STATIC) {
            world->bodies[i]->velocity = VEC2F_ADD(world->bodies[i]->velocity, \
            VEC2F_MUL1(world->gravity, world->bodies[i]->mass * dt_sec));
            pe_body_update(world->bodies[i], dt_sec);
            pe_aabb_copy(&world->tree->nodes[world->bodies[i]->id]->box, \
            &world->bodies[i]->aabb);
            pe_world_handle_collisions_for_body(world, world->bodies[i]);
        }
    }
    pe_bin_tree_update(world->tree);
}