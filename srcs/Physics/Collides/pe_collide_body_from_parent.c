/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - detect collisions
*/

#include "Physics/physics.h"

static void collide_leaf(pe_bin_tree_t *tree, int node_index, \
pe_body_t *body, pe_manifold_t **m_vec)
{
    if (tree->nodes[node_index]->tested == 0 && node_index != body->id && \
    pe_collide_aabbs(&tree->nodes[node_index]->box, &body->aabb)){
        pe_collide_bodies(tree->nodes[node_index]->body, body, m_vec);
    }
}

void pe_collide_body_from_parent(pe_bin_tree_t *tree, \
int parent_box_id, pe_body_t *body, pe_manifold_t **m_vec)
{
    my_vector(stack, int, tree->nb_nodes_set / 4);
    int index;

    my_vector_push((size_t **)&stack, parent_box_id);
    while (my_vector_empty((size_t *)stack) == 0) {
        index = my_vector_top((size_t *)stack);
        my_vector_pop((size_t **)&stack);
        if (tree->nodes[index]->is_leaf) {
            collide_leaf(tree, index, body, m_vec);
        } else {
            my_vector_push((size_t **)&stack, \
            (size_t)tree->nodes[index]->child1_id);
            my_vector_push((size_t **)&stack, \
            (size_t)tree->nodes[index]->child2_id);
        }
    }
}