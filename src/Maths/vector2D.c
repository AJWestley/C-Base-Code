/**
 * @file vector2D.c
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A special 2D case of the more general Vector in vector.c.
 *
 */

#include "vector2D.h"
#include <stdlib.h>
#include <math.h>

Vector2D *vector_new(double *values) {
    Vector2D *vector = zero_vector();
    if (!vector) return NULL;

    vector->x = values[0];
    vector->y = values[1];

    return vector;
}

Vector2D *zero_vector() {
    return calloc(sizeof(Vector2D), 1);
}

void vector_free(Vector2D *vector) {
    free(vector);
}

double dot(Vector2D *a, Vector2D *b) {
    return a->x * b->x + a->y * b->y;
}

Vector2D *vector_add(Vector2D *a, Vector2D *b) {
    Vector2D *sum = zero_vector();
    if (!sum) return NULL;

    sum->x = a->x + b->x;
    sum->y = a->y + b->y;

    return sum;
}

Vector2D *vector_subtract(Vector2D *a, Vector2D *b) {
    Vector2D *diff = zero_vector();
    if (!diff) return NULL;

    diff->x = a->x - b->x;
    diff->y = a->y - b->y;

    return diff;
}

Vector2D *vector_negate(Vector2D *a) {
    Vector2D *opp = zero_vector();
    if (!opp) return NULL;

    opp->x = -a->x;
    opp->y = -a->y;

    return opp;
}

double magnitude(Vector2D *vector) {
    return sqrt(vector->x * vector->x + vector->y * vector->y);
}

Vector2D *normalise(Vector2D *vector) {
    Vector2D *norm = zero_vector;
    if (!norm) return NULL;

    double mag = magnitude(vector);

    norm->x = vector->x / mag;
    norm->y = vector->y / mag;

    return norm;
}

int orthogonal(Vector2D *a, Vector2D *b) {
    return dot(a, b) == 0 ? TRUE : FALSE;
}