/**
 * @file queue.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A dynamic double-ended queue of linked nodes.
 *
 * @date 20-01-2024
 */

#ifndef WESTLEY_QUEUE_H
#define WESTLEY_QUEUE_H

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAILURE 0

#include "node.h"

/**
 * @brief Definition of a @ref Queue.
 */
typedef struct queue
{
    /** First Node of the Queue */
    Node *head;
    /** Last Node of the Queue */
    Node *tail;
    /** Number of Nodes in the Queue*/
    unsigned int size;
} Queue;

/**
 * @brief Allocate a new Queue for use.
 *
 * @returns Queue*
 */
Queue *queue_new();

/**
 * @brief Destroy a Queue and free back the memory.
 *
 * @param queue The Queue to free.
 */
void queue_free(Queue *queue);

/**
 * @brief Add an item to the back of the Queue.
 *
 * @param item The item to be added onto the Queue.
 * @param queue The queue to add to.
 *
 * @returns 1 if the enqueue was successful, 0 otherwise
 */
int enqueue(Item item, Queue *queue);

/**
 * @brief Remove an item from the front of a Queue.
 *
 * @param queue The Queue to be removed from.
 *
 * @returns 1 if the item was removed successfully, 0 otherwise.
 */
int dequeue(Queue *queue);

/**
 * @brief Gets the first Node in a Queue.
 *
 * @param queue The Queue to be evaluated.
 *
 * @returns The first Node, NULL if the Queue is empty.
 */
Node *get_front(Queue *queue);

/**
 * @brief Empties a Queue, freeing all internal Nodes.
 *
 * @param queue The Queue to be emptied.
 */
void clear(Queue *queue);

/**
 * @brief Finds whether an item is in a Queue or not.
 *
 * @param item The item to be searched for.
 * @param queue The Queue to be searched.
 *
 * @returns 1 if the Queue contains the item, 0 otherwise.
 */
int contains(Item item, Queue *queue);

/**
 * @brief Checks if a Queue contains any items.
 *
 * @param queue The Queue to be checked.
 *
 * @returns 1 if the Queue is empty, 0 otherwise.
 */
int empty(Queue *queue);

#endif