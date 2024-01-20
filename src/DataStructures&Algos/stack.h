/**
 * @file stack.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A dynamic array obeying the FIFO rule.
 *
 * @date 19-01-2024
 */

#ifndef WESTLEY_STACK_H
#define WESTLEY_STACK_H

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAILURE 0

// Define this as the datatype you wish the stack to be.
// Can be done in the file this is incuded by defining Item before the include.
#ifndef Item
#define Item double
#endif

/**
 * @brief Definition of a @ref Stack.
 */
typedef struct stack {
    /** Entries in the stack */
    Item *items;
    /** Length of the stack */
    unsigned int length;
    /** Allocated length of the stack.*/
    unsigned int _allocated;
} Stack;

/**
 * @brief Allocate a new Stack for use.
 *
 * @param length The initial length of Stack.
 * @returns Stack*
 */
Stack *stack_new(unsigned int size);

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
 * @returns 1 if the push was successful, 0 otherwise
 */
int push(Item item, Stack *stack);

/**
 * @brief Remove an item from the top of the stack.
 *
 * @param stack The stack to be popped from.
 * 
 * @returns 1 if the item was popped successfully, 0 otherwise.
 */
int pop(Stack *stack);

/**
 * @brief Gets the top element of a stack.
 *
 * @param stack The stack to be evaluated.
 * 
 * @returns The top item, NULL if the stack is empty.
 */
Item peek(Stack *stack);

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
 * @returns 1 if the stack contains the item, 0 otherwise.
 */
int contains(Item item, Stack *stack);

/**
 * @brief Checks if a stack contains any items.
 *
 * @param stack The stack to be checked.
 * 
 * @returns 1 if the stack is empty, 0 otherwise.
 */
int empty(Stack *stack);

/**
 * @brief Changes the size of a stack.
 *
 * @param new_size The new size of the stack.
 * @param stack The stack to be altered.
 * 
 * @returns 1 if the change was successful, 0 otherwise.
 */
int resize(int new_size, Stack *stack);

/**
 * @brief Reduces the size of a stack to its length.
 *
 * @param stack The stack to be compressed.
 * 
 * @returns 1 if the change was successful, 0 otherwise.
 */
int compress(Stack *stack);

#endif