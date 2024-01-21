/**
 * @file eratosthenes.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief An implementation of the sieve of Eratosthenes.
 *
 * @date 21-01-2024
 */

#ifndef WESTLEY_ERATOSTHENES_H
#define WESTLEY_ERATOSTHENES_H

#define Item unsigned int

#include "array_list.h"

/**
 * @brief Makes use of the sieve of eratosthenes to find all primes 
 *          until a given max.
 * 
 * @param max The given max
 * 
 * @returns An array list of all the found primes.
*/
ArrayList *primes(unsigned int max);

#endif 