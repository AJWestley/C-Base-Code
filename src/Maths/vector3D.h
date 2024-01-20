/**
 * @file vector3D.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A special 3D case of the more general Vector in vector.h.
 *
 * @date 20-01-2024
 *
 */

#ifndef WESTLEY_VECTOR_3D_H
#define WESTLEY_VECTOR_3D_H

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAILURE 0

/**
 * @brief Definition of a @ref Vector
 */
typedef struct vector3D
{
    double x;
    double y;
    double z;
} Vector3D;

/**
 * @brief Allocate a new 3D Vector for use.
 *
 * @param values The values to initialise the 3D Vector with.
 *
 * @returns Vector3D*
 */
Vector3D *vector_new(double *values);

/**
 * @brief Creates a 3D Vector of 0's.
 *
 * @returns A 3D Vector of 0's with the given length
 */
Vector3D *zero_vector();

/**
 * @brief Destroy a 3D Vector and free back the memory.
 *
 * @param vector The 3D Vector to free.
 */
void vector_free(Vector3D *vector);

/**
 * @brief Calculates the dot product of two 3D Vectors.
 *
 * @param a The first 3D Vector.
 * @param b The second 3D Vector.
 *
 * @returns The dot product of a and b;
 */
double dot(Vector3D *a, Vector3D *b);

/**
 * @brief Calculates the cross product of two 3D Vectors.
 *
 * @param a The first 3D Vector.
 * @param b The second 3D Vector.
 *
 * @returns The cross product of a and b;
 */
Vector3D *cross(Vector3D *a, Vector3D *b);

/**
 * @brief Calculates the sum of two 3D Vectors.
 *
 * @param a The first 3D Vector.
 * @param b The second 3D Vector.
 *
 * @returns The sum of a and b, returns NULL if a problem occurrs.
 */
Vector3D *vector_add(Vector3D *a, Vector3D *b);

/**
 * @brief Calculates the difference between two 3D Vectors.
 *
 * @param a The first 3D Vector.
 * @param b The second 3D Vector.
 *
 * @returns The difference between a and b, returns NULL if a problem occurrs.
 */
Vector3D *vector_subtract(Vector3D *a, Vector3D *b);

/**
 * @brief Flips the sign of all components of a 3D Vector.
 *
 * @param vector The 3D Vector to be negated.
 *
 * @returns A 3D Vector with the same magnitude of the input vector,
 *          pointing the opposite way, or NULL of a problem occurred.
 */
Vector3D *vector_negate(Vector3D *vector);

/**
 * @brief Calculates the magnitude of a 3D Vector.
 *
 * @param vector The 3D Vector to be evaluated.
 *
 * @returns The magnitude of the 3D Vector.
 */
double magnitude(Vector3D *vector);

/**
 * @brief Normalises a given 3D Vector.
 *
 * @param vector The 3D Vector to be normalised.
 *
 * @returns The normalised 3D Vector, NULL if a problem occurred.
 */
Vector3D *normalise(Vector3D *vector);

/**
 * @brief Calulates of two Vectors3D are orthogonal.
 *
 * @param a The first 3D Vector.
 * @param b The second 3D Vector.
 *
 * @returns 1 if the 3D Vectors are orthogonal, 0 otherwise.
 */
int orthogonal(Vector3D *a, Vector3D *b);

#endif