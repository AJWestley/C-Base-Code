/**
 * @file stack.c
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A dynamic array obeying the FIFO rule.
 *
 * @copyright Copyright (c) 2024, ajwestley.me
 *
 */

#include "stack.h"
#include <stdlib.h>
#include <string.h>

Stack *stack_new(unsigned int size)
{
    Stack *stack;
    
    if (size == 0) size = 4;

    stack = malloc(sizeof(Stack));

    stack->items = malloc(size * sizeof(Item));
    if (!stack->items) {
        free(stack);
        return NULL;
    }

    stack->length = 0;
    stack->_allocated = size;

    return stack;
}

void stack_free(Stack *stack) {
    free(stack->items);
    free(stack);
}