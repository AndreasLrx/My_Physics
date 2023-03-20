/*
** EPITECH PROJECT, 2020
** MyPhysics
** File description:
** Physics - Dynamic tree
*/

#ifndef PHYSICS_BINARY_TREE_H
#define PHYSICS_BINARY_TREE_H

#include "Physics/DynamicTree/tree_node.h"

typedef struct pe_bin_tree_t {
    struct pe_tree_node_t **nodes;
    int capacity;
    int nb_nodes_set;
    int *id_lefts;
    int root_id;
} pe_bin_tree_t;

pe_bin_tree_t *pe_bin_tree_init(int nb_objects_max);
void pe_bin_tree_destroy(pe_bin_tree_t *tree);

float pe_bin_tree_cost(pe_bin_tree_t *tree);
void pe_bin_tree_insert_body(pe_bin_tree_t *tree, pe_body_t *body);
void pe_bin_tree_update_parents_box(
    pe_bin_tree_t *tree, pe_tree_node_t *from_node);
int pe_bin_tree_find_best_sibling(
    pe_bin_tree_t *tree, pe_tree_node_t *new_node);
void pe_bin_tree_create_parent(
    pe_bin_tree_t *tree, pe_tree_node_t *sibling, pe_tree_node_t *new_node);

char pe_bin_tree_raycast(pe_bin_tree_t *tree, pe_vec2f_t p1, pe_vec2f_t p2);

pe_tree_node_t *pe_bin_tree_remove_node(
    pe_bin_tree_t *tree, int id, int destroy);
void pe_bin_tree_remove_body(pe_bin_tree_t *tree, pe_body_t *body);
void pe_bin_tree_reinsert(pe_bin_tree_t *tree, int id);
void pe_bin_tree_update(pe_bin_tree_t *tree);

#endif /* !PHYSICS_BINARY_TREE_H */
