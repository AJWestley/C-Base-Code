/**
 * @file array_list.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A dynamic array operating like Python's 'Lists'.
 *
 * To construct an Array List, use @ref array_list_new.
 * To destruct an Array List, use @ref array_list_free.
 *
 * To add an element to an Stack, use @ref append 
 * or @ref array_list_insert.
 *
 * To remove a value from an ArrayList, use @ref remove 
 * or @ref remove_index.
 *
 *
 * @date 19-01-2024
 *
 * @copyright Copyright (c) 2024, ajwestley.me
 *
 */

#ifndef WESTLEY_ARRAY_LIST_H
#define WESTLEY_ARRAY_LIST_H

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAILURE 0

// Define this as the datatype you wish the Array List to be.
// Can be done in the file this is incuded by defining Item before the include.
#ifndef Item
#define Item double
#endif

/**
 * @brief Definition of an @ref Array List.
 */
typedef struct _ArrayList
{
    /** Entries in the Array List */
    Item *items;
    /** Length of the Array List */
    unsigned int length;
    /** Allocated length of the Array List.*/
    unsigned int _allocated;
} ArrayList;

/**
 * @brief Allocate a new ArrayList for use.
 *
 * @param length The initial length of the Array List.
 * @returns ArrayList*
 */
ArrayList *array_list_new(unsigned int length);

/**
 * @brief Destroy an Array List and free back the memory.
 *
 * @param list The Array List to free.
 */
void array_list_free(ArrayList *list);

/**
 * @brief Add an item to a specified index of the Array List.
 *
 * @param index The index where the item must be inserted.
 * @param item The item to be inserted into the Array List.
 * @param list The Array List to insert to.
 *
 * @returns 1 if the insert was successful, 0 otherwise
 */
int insert(int index, Item item, ArrayList *list);

/**
 * @brief Add an item to the end of the Array List.
 *
 * @param item The item to be appended onto the Array List.
 * @param list The Array List to append.
 *
 * @returns 1 if the append was successful, 0 otherwise
 */
int append(Item item, ArrayList *list);

/**
 * @brief Remove an item from a specific position of the Array List.
 *
 * @param index The index of the item to be removed.
 * @param list The Array List to be removed from.
 *
 * @returns 1 if the item was removed successfully, 0 otherwise.
 */
int remove_index(int index, ArrayList *list);

/**
 * @brief Remove an item with a specified value from the Array List.
 *
 * @param value The value to be removed.
 * @param list The Array List to be removed from.
 *
 * @returns 1 if the item was removed successfully, 0 otherwise.
 */
int remove(Item value, ArrayList *list);

/**
 * @brief Gets the item in a particular index of an Array List.
 *
 * @param index The index to look for.
 * @param list The ArrayList to be evaluated.
 *
 * @returns The item, NULL if there is no item at that index.
 */
Item get(int index, ArrayList *list);

/**
 * @brief Empties an Array List.
 *
 * @param list The Array List to be emptied.
 */
void clear(ArrayList *list);

/**
 * @brief Gets the index of an item in an Array List.
 *
 * @param item The item to be searched for.
 * @param list The Array List to be searched.
 *
 * @returns The index of the sought after item, -1 if the item was not found.
 */
int find(Item item, ArrayList *list);

/**
 * @brief Finds whether an item is in an Array List or not.
 *
 * @param item The item to be searched for.
 * @param list The Array List to be searched.
 *
 * @returns 1 if the Array List contains the item, 0 otherwise.
 */
int contains(Item item, ArrayList *list);

/**
 * @brief Counts the number of occurences of a value in an Array List.
 *
 * @param value The value to be counted.
 * @param list The Array List to be searched.
 *
 * @returns The number of occurences of the given value.
 */
int count(Item value, ArrayList *list);

/**
 * @brief Checks if an Array List contains any items.
 *
 * @param list The Array List to be checked.
 *
 * @returns 1 if the Array List is empty, 0 otherwise.
 */
int empty(ArrayList *list);

/**
 * @brief Changes the size of an Array List.
 *
 * @param new_size The new size of the Array List.
 * @param list The Array List to be altered.
 *
 * @returns 1 if the change was successful, 0 otherwise.
 */
int resize(int new_size, ArrayList *list);

/**
 * @brief Reduces the size of an Array List to its length.
 *
 * @param list The Array List to be compressed.
 *
 * @returns 1 if the change was successful, 0 otherwise.
 */
int compress(ArrayList *list);

/**
 * @brief Reverses an Array List.
 *
 * @param list The Array List to be reversed.
 */
void reverse(ArrayList *list);

/**
 * @brief Sorts an Array List using insertion sort.
 *
 * @param list The Array List to be sorted.
 *
 * @returns 1 if the sort was successful, 0 otherwise.
 */
int insertion_sort(ArrayList *list);

/**
 * @brief Sorts an Array List using merge sort.
 *
 * @param list The Array List to be sorted.
 *
 * @returns 1 if the sort was successful, 0 otherwise.
 */
int merge_sort(ArrayList *list);

/**
 * @brief Sorts an Array List using quick sort.
 *
 * @param list The Array List to be sorted.
 *
 * @returns 1 if the sort was successful, 0 otherwise.
 */
int quick_sort(ArrayList *list);

#endif