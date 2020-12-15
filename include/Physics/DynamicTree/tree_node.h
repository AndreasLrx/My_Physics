/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - Binary tree nodes
*/

#ifndef PHYSICS_TREE_NODE_H
#define PHYSICS_TREE_NODE_H

#include "../Shapes/aabb_shape.h"
#include "../Body/body.h"

struct pe_bin_tree_t;

typedef struct pe_tree_node_t {
    pe_vec2f_t init_pos;
    pe_aabb_t box;
    pe_body_t *body;
    int id;
    int parent_id;
    int child1_id;
    int child2_id;
    char is_leaf;
    int tested;
} pe_tree_node_t;

pe_tree_node_t *pe_tree_node_init(struct pe_bin_tree_t *tree, \
pe_aabb_t *box, pe_body_t *body);
void pe_tree_node_destroy(pe_tree_node_t *node);

#endif /* !PHYSICS_TREE_NODE_H */