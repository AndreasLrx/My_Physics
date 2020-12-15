/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - display binary tree
*/

#include "Physics/physics.h"

void pe_bin_tree_display(pe_bin_tree_t *tree)
{
    my_vector(queue, int, 10);
    int index = tree->root_id;

    my_vector_push((size_t **)&queue, tree->root_id);
    while (!my_vector_empty((size_t *)queue)) {
        index = queue[0];
        printf("%4d->%-4d", tree->nodes[index]->parent_id, index);
        if (!tree->nodes[index]->is_leaf) {
            my_vector_push((size_t **)&queue, tree->nodes[index]->child1_id);
            my_vector_push((size_t **)&queue, tree->nodes[index]->child2_id);
        }
        my_vector_erase((size_t *)queue, 0, 0);
    }
}