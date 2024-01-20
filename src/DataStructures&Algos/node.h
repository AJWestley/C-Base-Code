/**
 * @file node.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A general Node definition.
 *
 * @date 20-01-2024
 */

#ifndef WESTLEY_NODE_H
#define WESTLEY_NODE_H

// Define this as the datatype you wish the Linked List to be.
// Can be done in the file this is incuded by defining Item before the include.
#ifndef Item
#define Item double
#endif

/**
 * @brief Definition of a @ref Linked List Node.
 */
typedef struct node
{
    /** The value of the Node */
    Item value;
    /** Pointer to the next Node */
    struct node *next;
} Node;

/**
 * @brief Allocate a new Node for use.
 *
 * @param value The value of the initialised Node.
 *
 * @returns Node*
 */
Node *node_new(Item value);

/**
 * @brief Destroy a Node and free back the memory.
 *
 * @param node The Node to free.
 */
void node_free(Node *node);

#endif