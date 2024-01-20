/**
 * @file point2D.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief Methods and types for 2D Points, co-ordinate conversions 
 *          and distance measures.
 *
 * @date 21-01-2024
 */

#ifndef WESTLEY_POINT_2D_H
#define WESTLEY_POINT_2D_H

/**
 * @brief Definition of a 2D Cartesian Point.
 */
typedef struct point2D {
    double x;
    double y;
} Point2D;


/**
 * @brief Creates a 2D Point with the given co-ord.
 *
 * @param x The position along the x-axis.
 * @param y The position along the y-axis.
 *
 * @returns A 2D Point with the given co-ord.
 */
Point2D point_new(double x, double y);

/**
 * @brief Calculates the value of the polar distance from origin, r.
 *
 * @param p The 2D Point to be converted.
 *
 * @returns The value of the polar distance from origin, r.
 */
double get_polar_r(Point2D p);

/**
 * @brief Calculates the value of the polar angle from x-axis, theta.
 *
 * @param p The 2D Point to be converted.
 *
 * @returns The value of the polar angle from x-axis, theta.
 */
double get_polar_theta(Point2D p);

/**
 * @brief Calculates the manhattan distance between two 2D Points.
 * 
 * @param a The first Point.
 * @param b The second Point.
 * 
 * @returns The manhattan distance between a and b.
*/
double manhattan_distance(Point2D a, Point2D b);

/**
 * @brief Calculates the euclidian distance between two 2D Points.
 *
 * @param a The first Point.
 * @param b The second Point.
 *
 * @returns The euclidian distance between a and b.
 */
double euclidian_distance(Point2D a, Point2D b);

#endif