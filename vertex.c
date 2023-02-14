/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Vertex
*/

#include <stdio.h>
#include <stdlib.h>
#include "vertex.h"
#include "new.h"

typedef struct {
    Class   base;
    int     x, y, z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg((*args), int);
    this->y = va_arg((*args), int);
    this->z = va_arg((*args), int);
}

static void Vertex_dtor(VertexClass *this)
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
    return;
}

static char *Vertex_str(VertexClass *this)
{
    char *str = malloc(sizeof(char) * 16 + (11 * 3));

    snprintf(str, (16 + (11 * 3)),
    "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return str;
}

static Object *Vertex_add(VertexClass *p1, VertexClass *p2)
{
    Object *ptr = NULL;

    if (!p1 || !p2)
        return NULL;
    ptr = new(Vertex, p1->x + p2->x, p1->y + p2->y, p1->z + p2->z);
    return (ptr);
}

static Object *Vertex_sub(VertexClass *p1, VertexClass *p2)
{
    Object *ptr = NULL;

    if (!p1 || !p2)
        return NULL;
    ptr = new(Vertex, p1->x - p2->x, p1->y - p2->y, p1->z - p2->z);
    return (ptr);
}

static const VertexClass _description = {
    {
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;
