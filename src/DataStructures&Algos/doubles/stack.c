/**
 * @file stack.c
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A dynamic floating-point array obeying the FIFO rule.
 *
 * @copyright Copyright (c) 2024, ajwestley.me
 *
 */

#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

Stack *stack_new(unsigned int size)
{
    Stack *stack;
    
    if (size == 0) size = 4;

    stack = malloc(sizeof(Stack));

    stack->items = malloc(size * sizeof(double));
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

int push(double item, Stack *stack) {
    if (stack->length == stack->_allocated) {
        int successful = change_size(2 * stack->length, stack);
        if (!successful) return FAILURE;
    }
    stack->items[stack->length] = item;
    stack->length++;
    return SUCCESS;
}

double pop(Stack *stack) {
    stack->length--;
    return stack->items[stack->length];
}

double peek(Stack *stack) {
    return stack->items[stack->length - 1];
}

void clear(Stack *stack) {
    stack->length = 0;
}

int find(double item, Stack *stack) {
    double err = 1 / 1048576;
    for (int i = 0; i < stack->length; i++) {
        if (fabs(stack->items[i] - item) < err) return i;
    }
    return -1;
}

int contains(double item, Stack *stack) {
    return find(item, stack) == -1 ? FALSE : TRUE;
}

int empty(Stack *stack) {
    return stack->length == 0 ? TRUE : FALSE;
}

int change_size(int new_size, Stack *stack) {
    if (new_size < stack->length) return FAILURE;

    int *items = realloc(stack->items, sizeof(int) * new_size);

    if (!items) return FAILURE;

    stack->items = items;
    stack->_allocated = new_size;

    return SUCCESS;
}

int compress(Stack *stack) {
    int successful = change_size(stack->length, stack);
    return successful;
}
