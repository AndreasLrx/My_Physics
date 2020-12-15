/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics debug
*/

#include <SFML/Graphics.h>
#include "Physics/physics.h"

#define M_TO_PX 32

typedef struct body_rect_t {
    pe_body_t *body;
    sfRectangleShape *shape;
    sfCircleShape *circle_shape;
    char type;
} body_rect_t;

sfVector2f pe_to_sf_v2f(pe_vec2f_t vec)
{
    return (sfVector2f){vec.x, vec.y};
}

body_rect_t *init_rect_from_body(pe_body_t *body)
{
    body_rect_t *rect = malloc(sizeof(body_rect_t));

    rect->body = body;
    rect->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(rect->shape, \
    (sfVector2f){body->aabb.size.x * M_TO_PX, body->aabb.size.y * M_TO_PX});
    sfRectangleShape_setOutlineColor(rect->shape, sfRed);
    sfRectangleShape_setOutlineThickness(rect->shape, -3);
    rect->type = POLYGON;
    return rect;
}

body_rect_t *init_circle_from_body(pe_body_t *body)
{
    body_rect_t *circle = malloc(sizeof(body_rect_t));

    circle->body = body;
    circle->circle_shape = sfCircleShape_create();
    sfCircleShape_setRadius(circle->circle_shape, \
    body->fixtures[0]->shape.shape.circle.radius * M_TO_PX);
    sfCircleShape_setOutlineColor(circle->circle_shape, sfRed);
    sfCircleShape_setOutlineThickness(circle->circle_shape, -3);
    circle->type = CIRCLE;
    return circle;
}

void pe_debug_draw_body(body_rect_t **rects, \
sfRenderWindow *window, int nb_bodys)
{
    for (int i = 0; i < nb_bodys; i++) {
        switch (rects[i]->type) {
        case POLYGON:
            sfRectangleShape_setPosition(rects[i]->shape, \
            (sfVector2f){(rects[i]->body->pos.x - \
                rects[i]->body->aabb.size.x / 2.f) * M_TO_PX, \
                (rects[i]->body->pos.y - \
                rects[i]->body->aabb.size.y / 2.f) * M_TO_PX});
            sfRenderWindow_drawRectangleShape(window, rects[i]->shape, NULL);
            break;
        case CIRCLE:
            sfCircleShape_setPosition(rects[i]->circle_shape, \
            (sfVector2f){(rects[i]->body->pos.x - \
                rects[i]->body->aabb.size.x / 2.f) * M_TO_PX, \
                (rects[i]->body->pos.y - \
                rects[i]->body->aabb.size.y / 2.f) * M_TO_PX});
            sfRenderWindow_drawCircleShape(window, \
            rects[i]->circle_shape, NULL);
        default:
            break;
        }
    }
}