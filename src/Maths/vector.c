/**
 * @file vector.c
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A static, mutable, 1D Vector with all associated operations.
 *
 */

#include "vector.h"
#include <stdlib.h>
#include <math.h>

Vector *vector_new(double *values, unsigned int length) {
    Vector *vector;

    vector = zero_vector(length);
    if (!vector) return NULL;

    for (int i = 0; i < length; i++) {
        vector->components[i] = values[i];
    }

    return vector;
}

Vector *zero_vector(unsigned int length) {
    Vector *vector;

    vector = malloc(sizeof(Vector));
    if (!vector) return NULL;

    vector->components = calloc(length, sizeof(double));
    if (!vector->components) {
        free(vector);
        return NULL;
    }

    vector->length = length;

    return vector;
}

void vector_free(Vector *vector) {
    free(vector->components);
    free(vector);
}

int pad(unsigned int length, double value, Vector *vector) {
    if (length < vector->length) return FAILURE;

    int *components = realloc(vector->components, sizeof(double) * length);

    if (!components) return FAILURE;

    vector->components = components;

    for (int i = vector->length; i < length; i++) {
        vector->components[i] = value;
    }

    vector->length = length;

    return SUCCESS;
}

int trim(unsigned int length, Vector *vector) {
    if (length > vector->length) return FAILURE;

    int *components = realloc(vector->components, sizeof(double) * length);

    if (!components) return FAILURE;

    vector->components = components;

    vector->length = length;

    return SUCCESS;
}

double dot(Vector *a, Vector *b) {
    double prod = 0;
    int length = MIN(a->length, b->length);

    for (int i = 0; i < length; i++) {
        prod += a->components[i] * b->components[i];
    }

    return prod;
}

Vector *vector_add(Vector *a, Vector *b) {
    if (a->length != b->length) {
        return NULL;
    }

    Vector *vector = zero_vector(a->length);
    if (!vector) return NULL;

    for (int i = 0; i < a->length; i++) {
        vector->components[i] = a->components[i] + b->components[i];
    }

    return vector;
}

Vector *vector_subtract(Vector *a, Vector *b) {
    if (a->length != b->length) {
        return NULL;
    }

    Vector *vector = zero_vector(a->length);
    if (!vector) return NULL;

    for (int i = 0; i < a->length; i++) {
        vector->components[i] = a->components[i] - b->components[i];
    }

    return vector;
}

Vector *vector_negate(Vector *vector) {
    Vector *opp = zero_vector(vector->length);
    if (!opp) return NULL;

    for (int i = 0; i < vector->length; i++) {
        opp->components[i] = -vector->components[i];
    }

    return opp;
}

double magnitude(Vector *vector) {
    double sq_sum = 0;
    for (int i = 0; i < vector->length; i++) {
        sq_sum += vector->components[i] * vector->components[i];
    }
    return sqrt(sq_sum);
}

Vector *normalise(Vector *vector) {
    double mag = magnitude(vector);

    Vector *norm = zero_vector(vector->length);
    if (!norm) return NULL;

    for (int i = 0; i < norm->length; i++) {
        norm->components[i] = vector->components[i] / mag;
    }

    return norm;
}

int orthogonal(Vector *a, Vector *b) {
    return dot(a, b) == 0 ? TRUE : FALSE;
}