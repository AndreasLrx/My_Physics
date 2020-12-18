/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - world
*/

#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H

#include "./Utils/utils.h"
#include "./DynamicTree/binary_tree.h"
#include "../my_containers/my_containers.h"

struct pe_body_t;
struct pe_manifold_t;

typedef struct pe_world_t {
    pe_vec2f_t gravity;
    struct pe_body_t **bodies;
    pe_bin_tree_t *tree;
} pe_world_t;

pe_world_t *pe_world_init(pe_vec2f_t gravity, \
unsigned short int bodies_initial_capacity);
void pe_world_destroy(pe_world_t *world);

int pe_world_add_body(pe_world_t *world, pe_body_t *body);
void pe_world_update(pe_world_t *world, float dt);
void pe_world_handle_collisions_for_body(pe_world_t *world, pe_body_t *body, \
struct pe_manifold_t **contact_vec);

#endif /* !PHYSICS_WORLD_H */