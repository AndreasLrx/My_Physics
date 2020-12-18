/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - Tree node init
*/

#include <stdlib.h>
#include "Physics/DynamicTree/binary_tree.h"
#include "Physics/DynamicTree/tree_node.h"

pe_tree_node_t *pe_tree_node_init(pe_bin_tree_t *tree, \
pe_aabb_t *box, pe_body_t *body)
{
    pe_tree_node_t *node;

    if (tree->nb_nodes_set >= tree->capacity)
        return NULL;
    node = malloc(sizeof(pe_tree_node_t));
    pe_aabb_copy(&node->box, box);
    node->init_pos = node->box.min;
    node->child1_id = -1;
    node->child2_id = -1;
    node->parent_id = -1;
    node->is_leaf = 1;
    node->tested = 0;
    node->id = tree->id_lefts[tree->nb_nodes_set];
    node->body = body;
    tree->nb_nodes_set++;
    tree->nodes[node->id] = node;
    if (body)
        body->id = node->id;
    return node;
}

void pe_tree_node_destroy(pe_tree_node_t *node)
{
    if (node->is_leaf && node->body) {
        pe_body_destroy(node->body);
    }
    free(node);
}