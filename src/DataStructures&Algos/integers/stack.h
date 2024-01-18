/**
 * @file stack.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A dynamic integer array obeying the FIFO rule.
 *
 * To construct a Stack, use @ref stack_new.
 * To destruct an Stack, use @ref stack_free.
 *
 * To add an element to an Stack, use @ref stack_push.
 *
 * To remove a value from an ArrayList, use @ref stack_pop.
 *
 *
 * @date 18-01-2024
 *
 * @copyright Copyright (c) 2024, ajwestley.me
 *
 */

#ifndef WESTLEY_STACK_H
#define WESTLEY_STACK_H

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAILURE 0

/**
 * @brief Definition of a @ref Stack.
 */
typedef struct _Stack {
    /** Entries in the stack */
    int *items;
    /** Length of the stack */
    unsigned int length;
    /** Allocated length of the stack.*/
    unsigned int _allocated;
} Stack;

/**
 * @brief Allocate a new Stack for use.
 *
 * @param length The initial length of Stack.
 * @return Stack*
 */
Stack *stack_new(unsigned int length);

/**
 * @brief Destroy a Stack and free back the memory.
 *
 * @param stack The stack to free.
 */
void stack_free(Stack *stack);

/**
 * @brief Add an item to the top of the stack.
 *
 * @param item The item to be pushed onto the stack.
 * @param stack The stack to push onto.
 * 
 * @return 1 if the push was successful, 0 otherwise
 */
int push(int item, Stack *stack);

/**
 * @brief Remove an item from the top of the stack.
 *
 * @param stack The stack to be popped from.
 * 
 * @return The item that was removed, NULL if the stack is empty.
 */
int pop(Stack *stack);

/**
 * @brief Gets the top element of a stack.
 *
 * @param stack The stack to be evaluated.
 * 
 * @return The top item, NULL if the stack is empty.
 */
int peek(Stack *stack);

/**
 * @brief Empties a stack.
 *
 * @param stack The stack to be emptied.
 */
void clear(Stack *stack);

/**
 * @brief Gets the index of an item in a stack.
 *
 * @param item The item to be searched for.
 * @param stack The stack to be searched.
 * 
 * @return The index of the sought after item, -1 if the item was not found.
 */
int find(int item, Stack *stack);

/**
 * @brief Finds whether an item is in a stack or not.
 *
 * @param item The item to be searched for.
 * @param stack The stack to be searched.
 * 
 * @return 1 if the stack contains the item, 0 otherwise.
 */
int contains(int item, Stack *stack);

/**
 * @brief Checks if a stack contains any items.
 *
 * @param stack The stack to be checked.
 * 
 * @return 1 if the stack is empty, 0 otherwise.
 */
int empty(Stack *stack);

/**
 * @brief Changes the size of a stack.
 *
 * @param new_size The new size of the stack.
 * @param stack The stack to be altered.
 * 
 * @return 1 if the change was successful, 0 otherwise.
 */
int resize(int new_size, Stack *stack);

/**
 * @brief Reduces the size of a stack to its length.
 *
 * @param stack The stack to be compressed.
 * 
 * @return 1 if the change was successful, 0 otherwise.
 */
int compress(Stack *stack);

/**
 * @brief Prints the contents of the stack.
 *
 * @param stack The stack to be printed.
 */
void print_stack(Stack *stack);

#endif