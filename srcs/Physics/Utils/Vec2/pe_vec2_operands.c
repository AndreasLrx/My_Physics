/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - vec2 operands
*/

#include "Physics/Utils/utils.h"

pe_vec2f_t pe_vec2f_operate(pe_vec2f_t v1, pe_vec2f_t v2, char operation)
{
    switch (operation) {
    case ADD:
        return (pe_vec2f_t){v1.x + v2.x, v1.y + v2.y};
    case SUBSTRACT:
        return (pe_vec2f_t){v1.x - v2.x, v1.y - v2.y};
    case MULTIPLY:
        return (pe_vec2f_t){v1.x * v2.x, v1.y * v2.y};
    case DIVIDE:
        return (pe_vec2f_t){v1.x / v2.x, v1.y / v2.y};
    case MODULO:
        return (pe_vec2f_t){v1.x + v2.x, v1.y + v2.y};
    default:
        return (pe_vec2f_t){0, 0};
    }
}

pe_vec2i_t pe_vec2i_operate(pe_vec2i_t v1, pe_vec2i_t v2, char operation)
{
    switch (operation) {
    case ADD:
        return (pe_vec2i_t){v1.x + v2.x, v1.y + v2.y};
    case SUBSTRACT:
        return (pe_vec2i_t){v1.x - v2.x, v1.y - v2.y};
    case MULTIPLY:
        return (pe_vec2i_t){v1.x * v2.x, v1.y * v2.y};
    case DIVIDE:
        return (pe_vec2i_t){v1.x / v2.x, v1.y / v2.y};
    case MODULO:
        return (pe_vec2i_t){v1.x + v2.x, v1.y + v2.y};
    default:
        return (pe_vec2i_t){0, 0};
    }
}

pe_vec2u_t pe_vec2u_operate(pe_vec2u_t v1, pe_vec2u_t v2, char operation)
{
    switch (operation) {
    case ADD:
        return (pe_vec2u_t){v1.x + v2.x, v1.y + v2.y};
    case SUBSTRACT:
        return (pe_vec2u_t){v1.x - v2.x, v1.y - v2.y};
    case MULTIPLY:
        return (pe_vec2u_t){v1.x * v2.x, v1.y * v2.y};
    case DIVIDE:
        return (pe_vec2u_t){v1.x / v2.x, v1.y / v2.y};
    case MODULO:
        return (pe_vec2u_t){v1.x + v2.x, v1.y + v2.y};
    default:
        return (pe_vec2u_t){0, 0};
    }
}