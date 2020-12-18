/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - update world
*/

#include "Physics/physics.h"

/*void pe_world_update(pe_world_t *world, float dt)
{
    int iterations = 10;
    float dt_sec = (dt / 1000.f) / (float)iterations;
    size_t nb_body = my_vector_get_size((size_t *)world->bodies);
    size_t nb_contacts;
    pe_manifold_t **contacts = (pe_manifold_t **)my_vector_init(sizeof(pe_manifold_t *), nb_body * 3);

    for (int ite = 0; ite < iterations; ite++) {
        for (size_t i = 0; i < nb_body; i++) {
            if (world->bodies[i]->body_type != STATIC) {
                pe_world_handle_collisions_for_body(world, world->bodies[i], contacts);
            }
        }
        for (size_t i = 0; i < nb_body; i++) {
            if (world->bodies[i]->body_type != STATIC) {
                pe_body_add_force(world->bodies[i], VEC2F_MUL1(world->gravity, world->bodies[i]->mass.mass));
                pe_body_integrate_forces(world->bodies[i], dt_sec / 2.0f);
            }
        }
        nb_contacts = my_vector_get_size((size_t *)contacts);
        for (size_t i = 0; i < nb_contacts; i++) {
            pe_resolve_collision_rotate(contacts[i]);
        }
        for (size_t i = 0; i < nb_body; i++) {
            if (world->bodies[i]->body_type != STATIC) {
                pe_body_update(world->bodies[i], dt_sec);
                pe_aabb_copy(&world->tree->nodes[world->bodies[i]->id]->box, \
                &world->bodies[i]->aabb);
                pe_body_clear_forces(world->bodies[i], 1, 1, 1);
            }
        }
        for (size_t i = 0; i < nb_contacts; i++)
            pe_position_correction(contacts[i]);
        my_vector_clear((size_t *)contacts, 1);
    }
    my_vector_free((size_t **)&contacts);
    pe_bin_tree_update(world->tree);
}*/

/*void pe_world_update(pe_world_t *world, float dt)
{
    float dt_sec = (dt / 1000.f);
    size_t nb_body = my_vector_get_size((size_t *)world->bodies);
    pe_manifold_t **contacts = (pe_manifold_t **)my_vector_init(sizeof(pe_manifold_t *), nb_body * 3);
    size_t nb_contacts;
    int iterations = 5;

    for (size_t i = 0; i < nb_body; i++) {
        for (size_t j = i + 1; j < nb_body; j++) {
            if (world->bodies[i]->body_type == STATIC && world->bodies[j]->body_type == STATIC)
                continue;
            if (pe_collide_aabbs(&world->bodies[i]->aabb, &world->bodies[j]->aabb)){
                pe_collide_bodies(world->bodies[i], world->bodies[j], contacts);
            }
        }
    }
    for (size_t i = 0; i < nb_body; i++) {
        pe_body_add_force(world->bodies[i], VEC2F_MUL1(world->gravity, world->bodies[i]->mass.mass));
        pe_body_integrate_forces(world->bodies[i], dt_sec);
    }
    nb_contacts = my_vector_get_size((size_t *)contacts);
    for (size_t i = 0; i < nb_contacts; i++)
        pe_manifold_init(contacts[i], dt_sec, world->gravity);
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < nb_contacts; j++)
            pe_resolve_collision_rotate(contacts[j]);
    }
    for (size_t i = 0; i < nb_body; i++) 
        pe_body_update(world->bodies[i], dt_sec);
    for (int j = 0; j < nb_contacts; j++)
        pe_position_correction(contacts[j]);
    for (size_t i = 0; i < nb_body; i++) 
        pe_body_clear_forces(world->bodies[i], 1, 1, 1);
    my_vector_clear((size_t *)contacts, 1);
    my_vector_free((size_t **)&contacts);
}*/

void pe_world_update(pe_world_t *world, float dt)
{
    float dt_sec = (dt / 1000.f);
    size_t nb_body = my_vector_get_size((size_t *)world->bodies);
    pe_manifold_t **contacts = NULL;//(pe_manifold_t **)my_vector_init(sizeof(pe_manifold_t *), nb_body * 3);
    //size_t nb_contacts;

    for (size_t i = 0; i < nb_body; i++) {
        if (world->bodies[i]->body_type != STATIC) {
            pe_body_add_force(world->bodies[i], VEC2F_MUL1(world->gravity, world->bodies[i]->mass.mass));
            pe_body_integrate_forces(world->bodies[i], dt_sec);
            pe_body_update(world->bodies[i], dt_sec);
            pe_aabb_copy(&world->tree->nodes[world->bodies[i]->id]->box, \
            &world->bodies[i]->aabb);
        }
    }
    for (size_t i = 0; i < nb_body; i++) {
        if (world->bodies[i]->body_type != STATIC) {
            pe_world_handle_collisions_for_body(world, world->bodies[i], contacts);
        }
    }
    /*nb_contacts = my_vector_get_size((size_t *)contacts);
    for (size_t i = 0; i < nb_contacts; i++) {
        pe_resolve_collision_rotate(contacts[i]);
    }
    for (size_t i = 0; i < nb_contacts; i++) {
        pe_position_correction(contacts[i]);
        pe_aabb_copy(&world->tree->nodes[contacts[i]->af->body->id]->box, \
            &contacts[i]->af->body->aabb);
        pe_aabb_copy(&world->tree->nodes[contacts[i]->bf->body->id]->box, \
            &contacts[i]->bf->body->aabb);
        free(contacts[i]);
    }
    my_vector_free((size_t **)&contacts);*/
    pe_bin_tree_update(world->tree);
}