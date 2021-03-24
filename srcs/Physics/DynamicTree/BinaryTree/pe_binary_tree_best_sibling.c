/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - binary tree pick best sibling
*/

#include <stdio.h>
#include "my_containers/my_containers.h"
#include "Physics/DynamicTree/binary_tree.h"

static float get_direct_cost(pe_tree_node_t *node, pe_tree_node_t *new_node)
{
    pe_aabb_t buffer;

    return pe_aabb_area(pe_aabb_union(&buffer, &node->box, &new_node->box));
}

static float get_inherited_cost(pe_bin_tree_t *tree, pe_tree_node_t *node, \
pe_tree_node_t *new_node, int include_node)
{
    float area = pe_aabb_area(&node->box);
    float inherited = \
    (include_node) ? get_direct_cost(node, new_node) - area : 0;
    pe_tree_node_t *current = node;

    while (current->parent_id != -1) {
        current = tree->nodes[current->parent_id];
        area = pe_aabb_area(&current->box);
        inherited += get_direct_cost(current, new_node) - area;
    }
    return inherited;
}

static void push_childs(pe_bin_tree_t *tree, int *queue, float *costs, \
pe_tree_node_t *new_node)
{
    costs[1] = costs[2] + (costs[1] - (costs[2] + \
    pe_aabb_area(&tree->nodes[queue[0]]->box))) + \
    pe_aabb_area(&new_node->box);
    if (costs[1] < costs[0] && !tree->nodes[queue[0]]->is_leaf) {
        printf("push childs\n");
        my_vector_push((size_t **)&queue, \
        tree->nodes[queue[0]]->child1_id);
        my_vector_push((size_t **)&queue, \
        tree->nodes[queue[0]]->child2_id);
    }
}

/*
** Costs :
** 0 : best
** 1 : current
** 2 : inherited
*/
int pe_bin_tree_find_best_sibling(pe_bin_tree_t *tree, pe_tree_node_t *new_node)
{
    float costs[3] = {0};
    int best = tree->root_id;
    costs[0] = get_direct_cost(tree->nodes[tree->root_id], new_node);
    my_vector(queue, int, 5);

    my_vector_push((size_t **)&queue, best);
    while (!my_vector_empty((size_t *)queue)) {
        costs[2] = \
        get_inherited_cost(tree, tree->nodes[queue[0]], new_node, 0);
        costs[1] = costs[2] + \
        get_direct_cost(tree->nodes[queue[0]], new_node);
        if (costs[1] < costs[0]) {
            costs[0] = costs[1];
            best = queue[0];
            push_childs(tree, queue, costs, new_node);
        }
        my_vector_erase((size_t *)queue, 0, 0);
    }
    my_vector_free((size_t **)&queue);
    return best;
}