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
#include <stdio.h>
#include <math.h>

Stack *stack_new(unsigned int size)
{
    Stack *stack;
    
    if (size == 0) size = 4;

    stack = malloc(sizeof(Stack));
    if (!stack) return NULL;

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

int push(Item item, Stack *stack) {
    if (stack->length == stack->_allocated) {
        int successful = resize(2 * stack->length, stack);
        if (!successful) return FAILURE;
    }
    stack->items[stack->length] = item;
    stack->length++;
    return SUCCESS;
}

int pop(Stack *stack) {
    if (stack->length = 0) return FAILURE;
    stack->length--;
    return SUCCESS;
}

Item peek(Stack *stack) {
    return stack->items[stack->length - 1];
}

void clear(Stack *stack) {
    stack->length = 0;
}

int contains(Item item, Stack *stack) {
    double err = 1 / 1048576;
    for (int i = 0; i < stack->length; i++) {
        if (fabs(stack->items[i] - item) < err) return TRUE;
    }
    return FALSE;
}

int empty(Stack *stack) {
    return stack->length == 0 ? TRUE : FALSE;
}

int resize(int new_size, Stack *stack) {
    if (new_size < stack->length) return FAILURE;

    int *items = realloc(stack->items, sizeof(int) * new_size);

    if (!items) return FAILURE;

    stack->items = items;
    stack->_allocated = new_size;

    return SUCCESS;
}

int compress(Stack *stack) {
    return resize(stack->length, stack);
}
