/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - binary tree cost fcts
*/

#include "Physics/DynamicTree/binary_tree.h"

static float get_area(pe_bin_tree_t *tree, int id)
{
    pe_tree_node_t *node = tree->nodes[id];
    float area = pe_aabb_area(&node->box);

    if (!tree->nodes[node->child1_id]->is_leaf)
        area += get_area(tree, node->child1_id);
    if (!tree->nodes[node->child2_id]->is_leaf)
        area += get_area(tree, node->child2_id);
    return area;
}

float pe_bin_tree_cost(pe_bin_tree_t *tree)
{
    return get_area(tree, tree->root_id);
}