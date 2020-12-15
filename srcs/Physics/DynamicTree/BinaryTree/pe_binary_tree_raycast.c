/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - tree raycast
*/

#include "Physics/DynamicTree/binary_tree.h"
#include "Physics/Raycast/raycast.h"
#include "my_containers/my_containers.h"

char pe_bin_tree_raycast(pe_bin_tree_t *tree, pe_vec2f_t p1, pe_vec2f_t p2)
{
    int index;
    my_vector(stack, int, tree->nb_nodes_set / 4);

    my_vector_push((size_t **)&stack, (size_t)tree->root_id);
    while (my_vector_empty((size_t *)stack) == 0) {
        index = my_vector_top((size_t *)stack);
        my_vector_pop((size_t **)&stack);
        if (!pe_raycast_hit_aabb(&tree->nodes[index]->box, p1, p2))
            continue;
        if (tree->nodes[index]->is_leaf)
            return 1;
        else {
            my_vector_push((size_t **)&stack, \
            (size_t)tree->nodes[index]->child1_id);
            my_vector_push((size_t **)&stack, \
            (size_t)tree->nodes[index]->child2_id);
        }
    }
    return 0;
}