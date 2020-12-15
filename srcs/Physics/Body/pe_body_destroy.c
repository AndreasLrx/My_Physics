/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body destroy
*/

#include "Physics/physics.h"

void pe_body_destroy(pe_body_t *body)
{
    size_t nb_fixtures = my_vector_get_size((size_t *)body->fixtures);
    size_t nb_moves = my_vector_get_size((size_t *)body->moves);

    for (size_t i = 0; i < nb_fixtures; i++)
        pe_fixture_destroy(body->fixtures[i]);
    for (size_t i = 0; i < nb_moves; i++)
        free(body->moves[i]);
    my_vector_free((size_t **)&body->fixtures);
    my_vector_free((size_t **)&body->moves);
    free(body);
}