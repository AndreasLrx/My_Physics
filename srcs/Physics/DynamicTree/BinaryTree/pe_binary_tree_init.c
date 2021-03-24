/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - binary tree init
*/

#include "Physics/physics.h"

pe_bin_tree_t *pe_bin_tree_init(int nb_objects_max)
{
    pe_bin_tree_t *tree = malloc(sizeof(pe_bin_tree_t));

    tree->capacity = MIN(nb_objects_max, 100000) * 2 - 1;
    tree->id_lefts = malloc(sizeof(int) * tree->capacity);
    tree->root_id = 0;
    tree->nb_nodes_set = 0;
    tree->nodes = malloc(sizeof(pe_tree_node_t *) * tree->capacity);
    for (int i = 0; i < tree->capacity; i++) {
        tree->nodes[i] = NULL;
        tree->id_lefts[i] = i;
    }
    return tree;
}

static void destroy_node_rec(pe_bin_tree_t *tree, int id)
{
    pe_tree_node_t *node = tree->nodes[id];

    if (node->child1_id != -1)
        destroy_node_rec(tree, node->child1_id);
    if (node->child2_id != -1)
        destroy_node_rec(tree, node->child2_id);
    pe_tree_node_destroy(node);
}

void pe_bin_tree_destroy(pe_bin_tree_t *tree)
{
    if (tree->nb_nodes_set > 0)
        destroy_node_rec(tree, tree->root_id);
    free(tree->nodes);
    free(tree->id_lefts);
    free(tree);
}