/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physiscs - circle shape
*/

#ifndef PHYSICS_CIRCLE_SHAPE_H
#define PHYSICS_CIRCLE_SHAPE_H

struct pe_shape_t;

/*
** Units :
** Radius
**    - meter
*/
typedef struct pe_circle_shape_t {
    float radius;
} pe_circle_shape_t;

void pe_shape_init_circle(struct pe_shape_t *shape, \
float radius, pe_vec2f_t pos);
char pe_collide_circles(struct pe_shape_t *c1, struct pe_shape_t *c2);

#endif /* !PHYSICS_CIRCLE_SHAPE_H */