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

double get_component(int index, Vector *vector) {
    return vector->components[index];
}

void set_component(int index, double value, Vector *vector) {
    vector->components[index] = value;
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
