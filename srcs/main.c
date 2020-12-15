/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <unistd.h>
#include <time.h>

#include "Physics/physics.h"
#include <stdio.h>

struct body_rect_t;

struct body_rect_t *init_rect_from_body(pe_body_t *body);
void pe_debug_draw_body(struct body_rect_t **rects, \
sfRenderWindow *window, int nb_bodys);
struct body_rect_t *init_circle_from_body(pe_body_t *body);

struct body_rect_t *create_ground(pe_world_t *world)
{
    pe_body_t *ground = pe_body_init(STATIC, 1, 0);
    pe_fixture_t *ground_fixture = pe_fixture_init();

    ground->pos = VEC2F(5, 10);
    pe_shape_init_rect(&ground_fixture->shape, VEC2F(0, 0), VEC2F(10, 1));
    pe_body_add_fixture(ground, ground_fixture);
    pe_world_add_body(world, ground);
    return init_rect_from_body(ground);
}

struct body_rect_t *create_box(pe_world_t *world, pe_vec2f_t pos, int circle)
{
    pe_body_t *box = pe_body_init(DYNAMIC, 1, 3);
    pe_fixture_t *box_fixture = pe_fixture_init();

    box->pos = pos;
    if (circle) {
        pe_shape_init_circle(&box_fixture->shape, 0.5, VEC2F(0, 0));
        box_fixture->density = 2;
    }
    pe_body_add_fixture(box, box_fixture);
    pe_world_add_body(world, box);
    return (circle) ? init_circle_from_body(box) : init_rect_from_body(box);
}

int main(int argc, char **argv)
{
    sfRenderWindow *window = sfRenderWindow_create(\
    (sfVideoMode){1280, 720, 32}, "physics tests", sfClose, NULL);
    sfClock *clock = sfClock_create();
    time_t new_time;
    time_t frame_time;
    time_t current_time = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
    int accumulator = 0.0f;
    pe_world_t *world = pe_world_init(VEC2F(0, 9.81), 100);
    const int MS_PER_UPDATE = 5;
    int nb_bodies = 2;
    struct body_rect_t *bodys[nb_bodies];
    my_vector(mouse_boxes, struct body_rect_t *, 10);
    sfEvent event;

    bodys[0] = create_ground(world);
    for (int i = 0; i < nb_bodies - 1; i++)
        bodys[i + 1] = create_box(world, VEC2F(5, 0), 0);
    while (sfRenderWindow_isOpen(window)) {
        new_time = sfTime_asMilliseconds(sfClock_getElapsedTime(clock));
        frame_time = new_time - current_time;
        current_time = new_time;
        accumulator += frame_time;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (sfEvtClosed == event.type) {
                sfRenderWindow_close(window);
            }
            if (sfEvtMouseButtonPressed == event.type && \
            event.mouseButton.button == sfMouseLeft) {
                my_vector_push((size_t **)&mouse_boxes, \
                (size_t)create_box(world, \
                VEC2F(sfMouse_getPositionRenderWindow(window).x / 32.f, \
                sfMouse_getPositionRenderWindow(window).y / 32.f), 0));
            }
            if (sfEvtMouseButtonPressed == event.type && \
            event.mouseButton.button == sfMouseRight) {
                my_vector_push((size_t **)&mouse_boxes, \
                (size_t)create_box(world, \
                VEC2F(sfMouse_getPositionRenderWindow(window).x / 32.f, \
                sfMouse_getPositionRenderWindow(window).y / 32.f), 1));
            }
        }
        while (accumulator >= MS_PER_UPDATE) {
            accumulator -= MS_PER_UPDATE;
            pe_world_update(world, MS_PER_UPDATE);
        }
        sfRenderWindow_clear(window, sfBlack);
        pe_debug_draw_body(bodys, window, nb_bodies);
        pe_debug_draw_body(mouse_boxes, window, \
        my_vector_get_size((size_t *)mouse_boxes));
        sfRenderWindow_display(window);
    }
    pe_world_destroy(world);
}