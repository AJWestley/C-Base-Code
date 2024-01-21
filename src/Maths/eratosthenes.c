/**
 * @file eratosthenes.c
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief An implementation of the sieve of Eratosthenes.
 *
 */

#include "eratosthenes.h"
#include <stdlib.h>

ArrayList *primes(unsigned int max) {
    unsigned int len = max - 1;
    unsigned int *nums = malloc(len * sizeof(unsigned int));
    if (!nums) return NULL;

    int i;
    for (i = 0; i < len; i++) {
        nums[i] = i + 2;
    }

    ArrayList *prms = array_list_new(0);

    for (i = 0; i < len; i++) {
        if (nums[i] == 0) continue;
        if (!append(nums[i], prms)) {
            free(nums);
            array_list_free(prms);
            return NULL;
        }
        for (int j = i + nums[i]; j < len; j += nums[i]) {
            nums[j] = 0;
        }
    }

    return prms;
}