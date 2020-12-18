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

    for (size_t i = 0; i < nb_fixtures; i++)
        pe_fixture_destroy(body->fixtures[i]);
    my_vector_free((size_t **)&body->fixtures);
    free(body);
}