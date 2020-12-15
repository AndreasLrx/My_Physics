/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - tree update
*/

#include "Physics/physics.h"

void pe_bin_tree_update(pe_bin_tree_t *tree)
{
    pe_tree_node_t *node;

    for (int i = 0; i < tree->nb_nodes_set; i++) {
        node = tree->nodes[tree->id_lefts[i]];
        if (node->is_leaf && (\
        fabsf(node->init_pos.x - node->box.min.x) > node->box.size.x / 2.f || \
        fabsf(node->init_pos.y - node->box.min.y) > node->box.size.y / 2.f)) {
            pe_bin_tree_reinsert(tree, node->id);
            node->init_pos = node->box.min;
        }
    }
}