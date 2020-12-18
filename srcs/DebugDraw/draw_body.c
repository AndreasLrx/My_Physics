/*
** EPITECH PROJECT, 2020
** My Physics
** File description:
** Debug - draw body
*/

#include "DebugDraw/debug_draw.h"

void sf_body_draw(sf_body_t *body, sfRenderWindow *window)
{
    size_t nb_circle = my_vector_get_size((size_t *)body->circles);
    size_t nb_polys = my_vector_get_size((size_t *)body->polys);

    //sfRenderWindow_drawRectangleShape(window, body->aabb, NULL);
    for (size_t i = 0; i < nb_circle; i++) {
        sfRenderWindow_drawCircleShape(window, body->circles[i], NULL);
    }
    for (size_t i = 0; i < nb_polys; i++) {
        sfRenderWindow_drawConvexShape(window, body->polys[i], NULL);
    }
    sfRenderWindow_drawCircleShape(window, body->com, NULL);
    sfRenderWindow_drawPrimitives(window, \
    body->orientation_vertices, 2, sfLines, NULL);
}

void sf_body_draw_vec(sf_body_t **vec, sfRenderWindow *window)
{
    size_t nb_bodies = my_vector_get_size((size_t *)vec);

    for (size_t i = 0; i < nb_bodies; i++) {
        sf_body_draw(vec[i], window);
    }
}