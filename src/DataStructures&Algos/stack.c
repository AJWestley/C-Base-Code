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
    ItemFreeFunc free_item = stack->_free_item;
    for (int i = 0; i < stack->length; i++) {
        free_item(stack->items[i]);
    }
    free(stack->items);
    free(stack);
}

int push(Item item, Stack *stack) {
    if (stack->length == stack->_allocated) {
        int successful = change_size(2 * stack->length, stack);
        if (!successful) return FAILURE;
    }
    stack->items[stack->length] = item;
    stack->length++;
    return SUCCESS;
}

Item pop(Stack *stack) {
    stack->length--;
    return stack->items[stack->length];
}

Item peek(Stack *stack) {
    return stack->items[stack->length - 1];
}

void clear(Stack *stack) {
    stack->length = 0;
}

int find(Item item, Stack *stack, CompareFunc cmp) {
    for (int i = 0; i < stack->length; i++) {
        if (cmp(stack->items[i], item) == 0) return i;
    }
    return -1;
}

int contains(Item item, Stack *stack, CompareFunc cmp) {
    return find(item, stack, cmp) == -1 ? FALSE : TRUE;
}

void empty(Stack *stack) {
    return stack->length == 0 ? TRUE : FALSE;
}

int change_size(int new_size, Stack *stack) {
    if (new_size < stack->length) return FAILURE;

    Item *items = realloc(stack->items, sizeof(Item) * new_size);

    if (!items) return FAILURE;

    stack->items = items;
    stack->_allocated = new_size;

    return SUCCESS;
}

int compress(Stack *stack) {
    int successful = change_size(stack->length, stack);
    return successful;
}