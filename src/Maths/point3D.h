/**
 * @file point3D.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief Methods and types for 3D Points, co-ordinate conversions
 *          and distance measures.
 *
 * @date 21-01-2024
 */

#ifndef WESTLEY_POINT_3D_H
#define WESTLEY_POINT_3D_H

/**
 * @brief Definition of a 3D Cartesian Point.
 */
typedef struct point3D
{
    double x;
    double y;
    double z;
} Point3D;

/**
 * @brief Creates a 3D Point with the given co-ord.
 *
 * @param x The position along the x-axis.
 * @param y The position along the y-axis.
 * @param z The position along the z-axis.
 *
 * @returns A 3D Point with the given co-ord.
 */
Point3D point_new(double x, double y, double z);

/**
 * @brief Calculates the value of the spherical co-ordinate component, r.
 *
 * @param p The 3D Point to be converted.
 *
 * @returns The value of the spherical co-ordinate component, r.
 */
double get_spherical_r(Point3D p);

/**
 * @brief Calculates the value of the spherical co-ordinate component, phi.
 *
 * @param p The 3D Point to be converted.
 *
 * @returns The value of the spherical co-ordinate component, phi.
 */
double get_spherical_phi(Point3D p);

/**
 * @brief Calculates the value of the spherical co-ordinate component, theta.
 *
 * @param p The 3D Point to be converted.
 *
 * @returns The value of the spherical co-ordinate component, theta.
 */
double get_spherical_theta(Point3D p);

/**
 * @brief Calculates the manhattan distance between two 3D Points.
 *
 * @param a The first Point.
 * @param b The second Point.
 *
 * @returns The manhattan distance between a and b.
 */
double manhattan_distance(Point3D a, Point3D b);

/**
 * @brief Calculates the euclidian distance between two 3D Points.
 *
 * @param a The first Point.
 * @param b The second Point.
 *
 * @returns The euclidian distance between a and b.
 */
double euclidian_distance(Point3D a, Point3D b);

#endif