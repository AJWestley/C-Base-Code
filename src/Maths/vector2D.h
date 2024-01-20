/**
 * @file vector2D.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A special 2D case of the more general Vector in vector.h.
 *
 * @date 20-01-2024
 *
 */

#ifndef WESTLEY_VECTOR_2D_H
#define WESTLEY_VECTOR_2D_H

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAILURE 0

/**
 * @brief Definition of a @ref Vector
 */
typedef struct vector2D
{
    double x;
    double y;
} Vector2D;

/**
 * @brief Allocate a new 2D Vector for use.
 *
 * @param values The values to initialise the 2D Vector with.
 *
 * @returns Vector2D*
 */
Vector2D *vector_new(double *values);

/**
 * @brief Creates a 2D Vector of 0's.
 *
 * @returns A 2D Vector of 0's with the given length
 */
Vector2D *zero_vector();

/**
 * @brief Destroy a 2D Vector and free back the memory.
 *
 * @param vector The 2D Vector to free.
 */
void vector_free(Vector2D *vector);

/**
 * @brief Calculates the dot product of two 2D Vectors.
 *
 * @param a The first 2D Vector.
 * @param b The second 2D Vector.
 *
 * @returns The dot product of a and b;
 */
double dot(Vector2D *a, Vector2D *b);

/**
 * @brief Calculates the cross product of two 2D Vectors.
 *
 * @param a The first 2D Vector.
 * @param b The second 2D Vector.
 *
 * @returns The cross product of a and b;
 */
Vector2D *cross(Vector2D *a, Vector2D *b);

/**
 * @brief Calculates the sum of two 2D Vectors.
 *
 * @param a The first 2D Vector.
 * @param b The second 2D Vector.
 *
 * @returns The sum of a and b, returns NULL if a problem occurrs.
 */
Vector2D *vector_add(Vector2D *a, Vector2D *b);

/**
 * @brief Calculates the difference between two 2D Vectors.
 *
 * @param a The first 2D Vector.
 * @param b The second 2D Vector.
 *
 * @returns The difference between a and b, returns NULL if a problem occurrs.
 */
Vector2D *vector_subtract(Vector2D *a, Vector2D *b);

/**
 * @brief Flips the sign of all components of a 2D Vector.
 *
 * @param vector The 2D Vector to be negated.
 *
 * @returns A 2D Vector with the same magnitude of the input vector,
 *          pointing the opposite way, or NULL of a problem occurred.
 */
Vector2D *vector_negate(Vector2D *vector);

/**
 * @brief Calculates the magnitude of a 2D Vector.
 *
 * @param vector The 2D Vector to be evaluated.
 *
 * @returns The magnitude of the 2D Vector.
 */
double magnitude(Vector2D *vector);

/**
 * @brief Normalises a given 2D Vector.
 *
 * @param vector The 2D Vector to be normalised.
 *
 * @returns The normalised 2D Vector, NULL if a problem occurred.
 */
Vector2D *normalise(Vector2D *vector);

/**
 * @brief Calulates of two Vectors2D are orthogonal.
 *
 * @param a The first 2D Vector.
 * @param b The second 2D Vector.
 *
 * @returns 1 if the 2D Vectors are orthogonal, 0 otherwise.
 */
int orthogonal(Vector2D *a, Vector2D *b);

#endif