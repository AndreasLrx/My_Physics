/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - binary tree body reinsertion
*/

#include <stdio.h>
#include "Physics/DynamicTree/binary_tree.h"

void pe_bin_tree_reinsert(pe_bin_tree_t *tree, int id)
{
    pe_tree_node_t *node;
    int best_sibling = 0;

    if (tree->nb_nodes_set <= 3)
        return;
    node = pe_bin_tree_remove_node(tree, id, 0);
    node->init_pos = node->box.min;
    node->child1_id = -1;
    node->child2_id = -1;
    node->parent_id = -1;
    best_sibling = pe_bin_tree_find_best_sibling(tree, node);
    pe_bin_tree_create_parent(tree, tree->nodes[best_sibling], node);
}