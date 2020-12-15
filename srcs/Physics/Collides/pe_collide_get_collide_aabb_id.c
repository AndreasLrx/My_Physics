/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - get Node aabb index
*/

#include "Physics/physics.h"

static int test_extend(int *extended, pe_aabb_t *current_box, \
pe_aabb_t *body_box, pe_aabb_t *test_box)
{
    int was_extend = 0;

    if (pe_aabb_is_equal(body_box, body_box))
        was_extend = 1;
    if (current_box->min.x < body_box->min.x && extended[0] == 0){
        extended[0]++;
        was_extend = 1;
    }
    if (current_box->min.y < body_box->min.y && extended[1] == 0){
        extended[1]++;
        was_extend = 1;
    }
    if (current_box->max.x < body_box->max.x && extended[2] == 0){
        extended[2]++;
        was_extend = 1;
    }
    if (current_box->max.y < body_box->max.y && extended[3] == 0){
        extended[3]++;
        was_extend = 1;
    }
    return was_extend;
}

int pe_collide_get_collide_aabb_id(pe_bin_tree_t *tree, pe_body_t *body)
{
    int extended[4] = {0};
    pe_tree_node_t *current = tree->nodes[body->id];
    pe_aabb_t test_box;
    int parent_id;
    int was_extend = 1;

    pe_aabb_copy(&test_box, &body->aabb);
    while (current->parent_id != -1 && was_extend) {
        pe_aabb_copy(&test_box, &current->box);
        parent_id = current->parent_id;
        current = tree->nodes[parent_id];
        was_extend = test_extend(extended, &current->box, \
        &body->aabb, &test_box);
    }
    return parent_id;
}