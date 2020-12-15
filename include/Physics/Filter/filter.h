/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - filter
*/

#ifndef PHYSICS_FILTER_H
#define PHYSICS_FILTER_H

#include <stdint.h>

typedef struct pe_filter_t {
    int32_t category;
    int32_t mask;
    int32_t group;
} pe_filter_t;

void pe_filter_init(pe_filter_t *filter);

#endif /* !PHYSICS_FILTER_H */