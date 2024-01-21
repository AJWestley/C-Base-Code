/**
 * @file euclid_gcd.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief An implementation of the Euclid's algorithm.
 *
 */

#include "euclid_gcd.h"

int *gcd(int a, int b) {
    return a == 0 ? b : gcd(b % a, a);
}