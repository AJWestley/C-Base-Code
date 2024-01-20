/**
 * @file vector3D.c
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A special 3D case of the more general Vector in vector.c.
 *
 */

#include "vector3D.h"
#include <stdlib.h>
#include <math.h>

Vector3D *vector_new(double *values) {
    Vector3D *vector = zero_vector();
    if (!vector) return NULL;

    vector->x = values[0];
    vector->y = values[1];
    vector->z = values[2];

    return vector;
}

Vector3D *zero_vector() {
    return calloc(sizeof(Vector3D), 1);
}

void vector_free(Vector3D *vector) {
    free(vector);
}

double dot(Vector3D *a, Vector3D *b) {
    return a->x * b->x + a->y * b->y + a->z * b->z;
}

Vector3D *cross(Vector3D *a, Vector3D *b) {
    Vector3D *prod = zero_vector();
    if (!prod) return NULL;

    prod->x = a->y * b->z - a->z * b->y;
    prod->y = a->z * b->x - a->x * b->z;
    prod->z = a->x * b->y - a->y * b->x;

    return prod;
}

Vector3D *vector_add(Vector3D *a, Vector3D *b) {
    Vector3D *sum = zero_vector();
    if (!sum) return NULL;

    sum->x = a->x + b->x;
    sum->y = a->y + b->y;
    sum->z = a->z + b->z;

    return sum;
}

Vector3D *vector_subtract(Vector3D *a, Vector3D *b) {
    Vector3D *diff = zero_vector();
    if (!diff) return NULL;

    diff->x = a->x - b->x;
    diff->y = a->y - b->y;
    diff->z = a->z - b->z;

    return diff;
}

Vector3D *vector_negate(Vector3D *a) {
    Vector3D *opp = zero_vector();
    if (!opp) return NULL;

    opp->x = -a->x;
    opp->y = -a->y;
    opp->z = -a->z;

    return opp;
}

double magnitude(Vector3D *vector) {
    return sqrt(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z);
}

Vector3D *normalise(Vector3D *vector) {
    Vector3D *norm = zero_vector;
    if (!norm) return NULL;

    double mag = magnitude(vector);

    norm->x = vector->x / mag;
    norm->y = vector->y / mag;
    norm->z = vector->z / mag;

    return norm;
}

int orthogonal(Vector3D *a, Vector3D *b) {
    return dot(a, b) == 0 ? TRUE : FALSE;
}