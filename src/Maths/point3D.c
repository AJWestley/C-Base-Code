/**
 * @file point3D.c
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief Methods and types for 3D Points, co-ordinate conversions 
 *          and distance measures.
 *
 */

#include "point3D.h"
#include <math.h>

Point3D point_new(double x, double y, double z) {
    Point3D p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

double get_spherical_r(Point3D p) {
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

double get_spherical_phi(Point3D p) {
    int sgn_y = p.y >= 0 ? 1 : -1;
    return p.x == 0 && p.y == 0 ? 0 : sgn_y * acos(p.x / sqrt(p.x * p.x + p.y * p.y));
}

double get_spherical_theta(Point3D p) {
    return p.x == 0 && p.y == 0 && p.z == 0 ? 0 : acos(p.z / get_spherical_r(p));
}

double manhattan_distance(Point3D a, Point3D b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y) + fabs(a.z - b.z);
}

double euclidian_distance(Point3D a, Point3D b) {
    double x_diff = fabs(a.x - b.x);
    double y_diff = fabs(a.y - b.y);
    double z_diff = fabs(a.z - b.z);
    return sqrt(x_diff * x_diff + y_diff * y_diff + z_diff * z_diff);
}