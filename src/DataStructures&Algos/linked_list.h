/**
 * @file linked_list.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A dynamic list of linked nodes.
 *
 * @date 20-01-2024
 */

#ifndef WESTLEY_LINKED_LIST_H
#define WESTLEY_LINKED_LIST_H

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAILURE 0

#include "node.h"

/**
 * @brief Definition of a @ref Linked List.
 */
typedef struct linkedList {
    /** First Node of the Linked List */
    Node *root;
    /** Number of Nodes in the Linked List*/
    unsigned int size;
} LinkedList;

/**
 * @brief Allocate a new Linked List for use.
 *
 * @returns LinkedList*
 */
LinkedList *linked_list_new();

/**
 * @brief Destroy a Linked List and free back the memory.
 *
 * @param list The Linked List to free.
 */
void linked_list_free(LinkedList *list);

/**
 * @brief Add an item to the front of the Linked List.
 *
 * @param item The item to be added onto the Linked List.
 * @param list The List to add to.
 *
 * @returns 1 if the add was successful, 0 otherwise
 */
int add_front(Item item, LinkedList *list);

/**
 * @brief Add an item to the back of the Linked List.
 *
 * @param item The item to be added onto the Linked List.
 * @param list The List to add to.
 *
 * @returns 1 if the add was successful, 0 otherwise
 */
int add_back(Item item, LinkedList *list);

/**
 * @brief Remove an item from the front of a Linked List.
 *
 * @param list The Linked List to be removed from.
 *
 * @returns 1 if the item was removed successfully, 0 otherwise.
 */
int remove_front(LinkedList *list);

/**
 * @brief Remove an item from the front of a Linked List.
 *
 * @param list The Linked List to be removed from.
 *
 * @returns 1 if the item was removed successfully, 0 otherwise.
 */
int remove_back(LinkedList *list);

/**
 * @brief Gets the first Node in a Linked List.
 *
 * @param list The Linked List to be evaluated.
 *
 * @returns The first Node, NULL if the Linked List is empty.
 */
Node *get_front(LinkedList *list);

/**
 * @brief Gets the last Node in a Linked List.
 *
 * @param list The Linked List to be evaluated.
 *
 * @returns The last Node, NULL if the Linked List is empty.
 */
Node *get_back(LinkedList *list);

/**
 * @brief Empties a Linked List, freeing all internal Nodes.
 *
 * @param list The Linked List to be emptied.
 */
void clear(LinkedList *list);

/**
 * @brief Finds whether an item is in a Linked List or not.
 *
 * @param item The item to be searched for.
 * @param list The Linked List to be searched.
 *
 * @returns 1 if the Linked List contains the item, 0 otherwise.
 */
int contains(Item item, LinkedList *list);

/**
 * @brief Checks if a Linked List contains any items.
 *
 * @param list The Linked List to be checked.
 *
 * @returns 1 if the Linked List is empty, 0 otherwise.
 */
int empty(LinkedList *list);

#endif