/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - binary tree insert leaf
*/

#include <stdio.h>
#include "Physics/DynamicTree/binary_tree.h"

void pe_bin_tree_create_parent(pe_bin_tree_t *tree, pe_tree_node_t *sibling, \
pe_tree_node_t *new_node)
{
    pe_tree_node_t *node = pe_tree_node_init(tree, &sibling->box, NULL);

    node->child1_id = sibling->id;
    node->child2_id = new_node->id;
    node->is_leaf = 0;
    node->parent_id = sibling->parent_id;
    sibling->parent_id = node->id;
    new_node->parent_id = node->id;
    if (node->parent_id == -1)
        tree->root_id = node->id;
    pe_bin_tree_update_parents_box(tree, node);
}

void pe_bin_tree_update_parents_box(pe_bin_tree_t *tree, \
pe_tree_node_t *from_node)
{
    pe_tree_node_t *current = from_node;

    pe_aabb_union(&current->box, &tree->nodes[current->child1_id]->box, \
    &tree->nodes[current->child2_id]->box);
    while (current->parent_id != -1) {
        current = tree->nodes[current->parent_id];
        pe_aabb_union(&current->box, &tree->nodes[current->child1_id]->box, \
        &tree->nodes[current->child2_id]->box);
    }
}

void pe_bin_tree_insert_body(pe_bin_tree_t *tree, pe_body_t *body)
{
    int best_sibling = 0;
    pe_tree_node_t *node = pe_tree_node_init(tree, &body->aabb, body);

    if (tree->nb_nodes_set == 1){
        tree->root_id = node->id;
        return;
    }
    best_sibling = pe_bin_tree_find_best_sibling(tree, node);
    pe_bin_tree_create_parent(tree, tree->nodes[best_sibling], node);
}