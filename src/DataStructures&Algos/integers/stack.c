/**
 * @file stack.c
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A dynamic integer array obeying the FIFO rule.
 *
 * @copyright Copyright (c) 2024, ajwestley.me
 *
 */

#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Stack *stack_new(unsigned int size)
{
    Stack *stack;
    
    if (size == 0) size = 4;

    stack = malloc(sizeof(Stack));

    stack->items = malloc(size * sizeof(int));
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

int push(int item, Stack *stack) {
    if (stack->length == stack->_allocated) {
        int successful = resize(2 * stack->length, stack);
        if (!successful) return FAILURE;
    }
    stack->items[stack->length] = item;
    stack->length++;
    return SUCCESS;
}

int pop(Stack *stack) {
    stack->length--;
    return stack->items[stack->length];
}

int peek(Stack *stack) {
    return stack->items[stack->length - 1];
}

void clear(Stack *stack) {
    stack->length = 0;
}

int find(int item, Stack *stack) {
    for (int i = 0; i < stack->length; i++) {
        if (stack->items[i] == item) return i;
    }
    return -1;
}

int contains(int item, Stack *stack) {
    return find(item, stack) == -1 ? FALSE : TRUE;
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
    int successful = resize(stack->length, stack);
    return successful;
}

void print_stack(Stack *stack) {
    printf("[");
    if (stack->length > 0) {
        for (int i = 0; i < stack->length - 1; i++) {
            printf("%d, ", stack->items[i]);
        }
        printf("%d", stack->items[stack->length-1]);
    }
    printf("]\n");
    printf("Allocated: %d\nLength: %d\n", stack->_allocated, stack->length);
}
