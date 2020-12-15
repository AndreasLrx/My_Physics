/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - fixture destroy
*/

#include <stdlib.h>
#include "Physics/Fixture/fixture.h"

void pe_fixture_destroy(pe_fixture_t *fixture)
{
    pe_shape_destroy(&fixture->shape);
    free(fixture);
}