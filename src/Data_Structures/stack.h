/**
 * @file stack.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A dynamic array obeying the FIFO rule.
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

/**
 * @brief The type of a value to be stored in an @ref ArrayList.
 *        (void *) can be changed to int, long, or other types if needed.
 */
typedef union item {
    char c;
    short s;
    int i;
    long l;
    float f;
    double d;
    long double ld;
} Item;

/**
 * @brief Definition of a @ref Stack.
 */
typedef struct _Stack {
    /** Entries in the array */
    Item *items;
    /** Length of the array */
    unsigned int length;
    /** Allocated length of the array.*/
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
int push(Item item, Stack *stack);

/**
 * @brief Remove an item from the top of the stack.
 *
 * @param stack The stack to be popped from.
 * 
 * @return The item that was removed, NULL if the stack is empty.
 */
Item pop(Stack *stack);

/**
 * @brief Gets the top element of a stack.
 *
 * @param stack The stack to be evaluated.
 * 
 * @return The top item, NULL if the stack is empty.
 */
Item peek(Stack *stack);

/**
 * @brief Gets the index of an item in a stack.
 *
 * @param item The item to be searched for.
 * @param stack The stack to be searched.
 * 
 * @return The index of the sought after item, -1 if the item was not found.
 */
int find(Item item, Stack *stack);

/**
 * @brief Empties a stack.
 *
 * @param stack The stack to be emptied.
 */
void clear(Stack *stack);

/**
 * @brief Finds whether an item is in a stack or not.
 *
 * @param item The item to be searched for.
 * @param stack The stack to be searched.
 * 
 * @return 1 if the stack contains the item, 0 otherwise.
 */
int contains(Item item, Stack *stack);

/**
 * @brief Changes the size of a stack.
 *
 * @param new_size The new size of the stack.
 * @param stack The stack to be altered.
 * 
 * @return 1 if the change was successful, 0 otherwise.
 */
int change_size(int new_size, Stack *stack);

/**
 * @brief Reduces the size of a stack to its length.
 *
 * @param stack The stack to be compressed.
 * 
 * @return 1 if the change was successful, 0 otherwise.
 */
int compress(Stack *stack);

#endif