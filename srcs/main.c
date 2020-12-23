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
#include "DebugDraw/debug_draw.h"
#include <stdio.h>

sf_body_t *create_polygon(pe_world_t *world, pe_vec2f_t pos)
{
    pe_body_t *polygon = pe_body_init(DYNAMIC, 1, 0);
    pe_fixture_t *polygon_fixture = pe_fixture_init();
    sf_body_t *sf_body;

    polygon->pos = pos;
    pe_vec2f_t *vertices = malloc(sizeof(pe_vec2f_t) * 6);
    vertices[0] = VEC2F(0, -0.75);
    vertices[1] = VEC2F(0.5, -0.25);
    vertices[2] = VEC2F(0.5, 0.25);
    vertices[3] = VEC2F(0, 0.75);
    vertices[4] = VEC2F(-0.5, 0.25);
    vertices[5] = VEC2F(-0.5, -0.25);
    pe_shape_init_polygon(&polygon_fixture->shape, VEC2F(0, 0), vertices, 6);
    pe_body_add_fixture(polygon, polygon_fixture);
    sf_body = sf_body_init(polygon);
    sf_body_add_poly(sf_body, &polygon_fixture->shape);
    pe_world_add_body(world, polygon);
    return sf_body;
}

struct sf_body_t *create_ground(pe_world_t *world, int oriented)
{
    pe_body_t *ground = pe_body_init(STATIC, 1, 0);
    pe_fixture_t *ground_fixture = pe_fixture_init();
    sf_body_t *sf_body;

    ground->pos = VEC2F(5 + 15 * oriented + 3 * (oriented == -1) * 13, 10);
    pe_shape_init_rect(&ground_fixture->shape, VEC2F(0, 0), VEC2F(10, 1));
    pe_body_add_fixture(ground, ground_fixture);
    pe_body_set_angle(ground, oriented * TO_RAD(30));
    sf_body = sf_body_init(ground);
    sf_body_add_poly(sf_body, &ground_fixture->shape);
    pe_world_add_body(world, ground);
    return sf_body;
}

struct sf_body_t *create_box(pe_world_t *world, pe_vec2f_t pos, int circle)
{
    pe_body_t *box = pe_body_init(DYNAMIC, 1, 3);
    pe_fixture_t *box_fixture = pe_fixture_init();
    sf_body_t *sf_body;

    box->pos = pos;
    if (circle) {
        pe_shape_init_circle(&box_fixture->shape, 0.5, VEC2F(0, 0));
        //box_fixture->density = 2;
    }
    pe_body_add_fixture(box, box_fixture);
    sf_body = sf_body_init(box);
    if (circle)
        sf_body_add_circle(sf_body, &box_fixture->shape);
    else
        sf_body_add_poly(sf_body, &box_fixture->shape);
    pe_world_add_body(world, box);
    return sf_body;
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
    int nb_bodies = 3;
    my_vector(bodies, sf_body_t *, 10);
    sfEvent event;

    my_vector_push((size_t **)&bodies, (size_t)create_ground(world, 0));
    my_vector_push((size_t **)&bodies, (size_t)create_ground(world, 1));
    my_vector_push((size_t **)&bodies, (size_t)create_ground(world, -1));
    for (int i = 0; i < nb_bodies - 2; i++)
        my_vector_push((size_t **)&bodies, (size_t)create_box(world, VEC2F(20, 0), 1));
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
                my_vector_push((size_t **)&bodies, \
                (size_t)create_box(world, \
                VEC2F(sfMouse_getPositionRenderWindow(window).x / 32.f, \
                sfMouse_getPositionRenderWindow(window).y / 32.f), 0));
            }
            if (sfEvtMouseButtonPressed == event.type && \
            event.mouseButton.button == sfMouseRight) {
                my_vector_push((size_t **)&bodies, \
                (size_t)create_box(world, \
                VEC2F(sfMouse_getPositionRenderWindow(window).x / 32.f, \
                sfMouse_getPositionRenderWindow(window).y / 32.f), 1));
            }
            if (sfEvtKeyReleased == event.type && \
            event.key.code == sfKeyP) {
                my_vector_push((size_t **)&bodies, \
                (size_t)create_polygon(world, \
                VEC2F(sfMouse_getPositionRenderWindow(window).x / 32.f, \
                sfMouse_getPositionRenderWindow(window).y / 32.f)));
            }
        }
        while (accumulator >= MS_PER_UPDATE) {
            accumulator -= MS_PER_UPDATE;
            pe_world_update(world, MS_PER_UPDATE);
            sf_body_update_vec(bodies);
        }
        sfRenderWindow_clear(window, sfBlack);
        sf_body_draw_vec(bodies, window);
        sfRenderWindow_display(window);
    }
    pe_world_destroy(world);
}