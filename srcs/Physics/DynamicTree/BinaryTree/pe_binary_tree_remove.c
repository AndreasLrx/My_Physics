/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - remove node
*/

#include <stdlib.h>
#include <stdio.h>
#include "Physics/DynamicTree/binary_tree.h"

static void reassign_ids(pe_bin_tree_t *tree, pe_tree_node_t *ending_node, \
pe_tree_node_t *parent)
{
    int sibling_id;
    pe_tree_node_t *sibling;

    sibling_id = ((parent->child1_id != ending_node->id) ? \
parent->child1_id : parent->child2_id);
    sibling = tree->nodes[sibling_id];
    sibling->parent_id = parent->parent_id;
    if (parent->parent_id != -1) {
        if (tree->nodes[parent->parent_id]->child1_id == parent->id)
            tree->nodes[parent->parent_id]->child1_id = sibling_id;
        else
            tree->nodes[parent->parent_id]->child2_id = sibling_id;
    } else {
        tree->root_id = sibling_id;
    }
    tree->nb_nodes_set--;
    tree->id_lefts[tree->nb_nodes_set] = parent->id;
    tree->nodes[parent->id] = NULL;
    pe_tree_node_destroy(parent);
}

pe_tree_node_t *pe_bin_tree_remove_node(pe_bin_tree_t *tree, \
int id, int destroy)
{
    pe_tree_node_t *node = tree->nodes[id];
    int parent_id = node->parent_id;
    int grandparent_id = \
    (parent_id != -1) ? tree->nodes[parent_id]->parent_id : -1;

    if (parent_id != -1)
        reassign_ids(tree, node, tree->nodes[parent_id]);
    if (destroy) {
        tree->nb_nodes_set--;
        tree->id_lefts[tree->nb_nodes_set] = id;
        tree->nodes[id] = NULL;
        pe_tree_node_destroy(node);
        return NULL;
    }
    if (grandparent_id != -1)
        pe_bin_tree_update_parents_box(tree, tree->nodes[grandparent_id]);
    return node;
}

void pe_bin_tree_remove_body(pe_bin_tree_t *tree, pe_body_t *body)
{
    pe_bin_tree_remove_node(tree, body->id, 1);
}