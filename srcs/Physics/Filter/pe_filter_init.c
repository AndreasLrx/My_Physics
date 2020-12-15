/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - filter init
*/

#include "Physics/physics.h"

void pe_filter_init(pe_filter_t *filter)
{
    filter->mask = INT32_MAX;
    filter->category = INT32_MAX;
    filter->group = 0;
}