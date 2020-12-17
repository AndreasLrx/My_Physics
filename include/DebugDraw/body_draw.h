/*
** EPITECH PROJECT, 2020
** My Physics
** File description:
** My Physics - debug draw body struct
*/

#ifndef PHYSICS_DEBUG_BODY_H
#define PHYSICS_DEBUG_BODY_H

#include <SFML/Graphics.h>

struct pe_shape_t;

typedef struct sf_body_t {
    sfRectangleShape *aabb;
    sfCircleShape *com;
    sfVertex *orientation_vertices;
    int *types;
    sfConvexShape **polys;
    sfCircleShape **circles;
    struct pe_body_t *body;
} sf_body_t;

sf_body_t *sf_body_init(struct pe_body_t *body);
void sf_body_update_aabb(sf_body_t *body);

void sf_body_add_circle(sf_body_t *body, struct pe_shape_t *shape);
void sf_body_add_poly(sf_body_t *body, struct pe_shape_t *shape);

size_t sf_boddy_nb_fixtures(sf_body_t *body);

void sf_body_update(sf_body_t *body);
void sf_body_update_vec(sf_body_t **vec);
void sf_body_draw(sf_body_t *body, sfRenderWindow *window);
void sf_body_draw_vec(sf_body_t **vec, sfRenderWindow *window);

#endif /* !PHYSICS_DEBUG_BODY_H */