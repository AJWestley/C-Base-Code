/**
 * @file point2D.c
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief Methods and types for 2D Points, co-ordinate conversions 
 *          and distance measures.
 *
 */

#include "point2D.h"
#include <math.h>

Point2D point_new(double x, double y) {
    Point2D cart;
    cart.x = x;
    cart.y = y;
    return cart;
}

double get_polar_r(Point2D p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

double get_polar_theta(Point2D p) {
    if (p.x == 0 || p.y == 0) return 0;
    return p.x == 0 || p.y == 0 ? 0 : atan(p.y / p.x);
}

double manhattan_distance(Point2D a, Point2D b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

double euclidian_distance(Point2D a, Point2D b) {
    double x_diff = fabs(a.x - b.x);
    double y_diff = fabs(a.y - b.y);
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}