/**
 * @file vector.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A static, mutable, Vector with all associated operations.
 *
 * @date 19-01-2024
 *
 */

#ifndef WESTLEY_VECTOR_H
#define WESTLEY_VECTOR_H

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAILURE 0

#define MIN(a, b) a < b ? a : b

/**
 * @brief Definition of a @ref Vector
*/
typedef struct _Vector {
    double* components;
    unsigned int length;
} Vector;

/**
 * @brief Allocate a new Vector for use.
 *
 * @param values The values to initialise the Vector with.
 * @param length Length of the Vector.
 * 
 * @returns Vector*
 */
Vector *vector_new(double *values, unsigned int length);

/**
 * @brief Creates a Vector of 0's with a given length.
 *
 * @param length The length of the Vector to be created.
 *
 * @returns A Vector of 0's with the given length
 */
Vector *zero_vector(unsigned int length);

/**
 * @brief Destroy a Vector and free back the memory.
 *
 * @param vector The Vector to free.
 */
void vector_free(Vector *vector);

/**
 * @brief Pads a Vector with the given value.
 * 
 * @param length How long to make the Vector.
 * @param value The value to pad the Vector with.
 * @param vector The vector to pad.
 * 
 * @returns 1 if the padding was successful, 0 otherwise.
*/
int pad(unsigned int length, double value, Vector *vector);

/**
 * @brief Reduces the length of a Vector, cutting off the end values.
 *
 * @param length How long to make the Vector.
 * @param vector The Vector to trim.
 *
 * @returns 1 if the trimming was successful, 0 otherwise.
 */
int trim(unsigned int length, Vector *vector);

/**
 * @brief Calculates the dot product of two Vectors.
 * 
 * @param a The first Vector.
 * @param b The second Vector.
 * 
 * @returns The dot product of a and b, if a and be are not
 *          the same length, the excess components of the larger 
 *          Vector are skipped.
*/
double dot(Vector *a, Vector *b);

/**
 * @brief Calculates the sum of two Vectors.
 *
 * @param a The first Vector.
 * @param b The second Vector.
 *
 * @returns The sum of a and b, if a and b are not the same 
 *          length, returns NULL.
 */
Vector *vector_add(Vector *a, Vector *b);

/**
 * @brief Calculates the difference between two Vectors.
 *
 * @param a The first Vector.
 * @param b The second Vector.
 *
 * @returns The difference between a and b, if a and b are not 
 *          the same length, returns NULL.
 */
Vector *vector_subtract(Vector *a, Vector *b);

/**
 * @brief Flips the sign of all components of a Vector.
 *
 * @param vector The Vector to be negated.
 *
 * @returns A vector with the same magnitude of the input vector, 
 *          pointing the opposite way, or NULL of a problem occurred.
 */
Vector *vector_negate(Vector *vector);

/**
 * @brief Calculates the magnitude of a Vector.
 * 
 * @param vector The Vector to be evaluated.
 * 
 * @returns The magnitude of the Vector.
*/
double magnitude(Vector *vector);

/**
 * @brief Normalises a given Vector.
 *
 * @param vector The Vector to be normalised.
 * 
 * @returns The normalised Vector, NULL if a problem occurred.
 */
Vector *normalise(Vector *vector);

/**
 * @brief Calulates of two Vectors are orthogonal.
 *
 * @param a The first Vector.
 * @param b The second Vector.
 * 
 * @returns 1 if the Vectors are orthogonal, 0 otherwise.
 */
int orthogonal(Vector *a, Vector *b);

#endif