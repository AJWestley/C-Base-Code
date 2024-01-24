/**
 * @file hashmap.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A key-value Hash Map.
 *
 * @date 22-01-2024
 *
 */

#ifndef WESTLEY_HASHMAP_H
#define WESTLEY_HASHMAP_H

#define TRUE 1
#define FALSE 0

#define SUCCESS 1
#define FAILURE 0

#ifndef Key
#define Key char*
#endif

#ifndef Value
#define Value double
#endif


typedef struct hashItem {
    Key key;
    Value value;
    struct hashItem *next;
} HashItem;

typedef int (*HashFunc)(Key key, int length);

typedef int (*CmpFunc)(Key a, Key b);

typedef struct hashMap {
    /** The number of buckets in the Hash Map */
    unsigned int size;
    /** The number of key-value pairs in the Hash Map */
    unsigned int item_count;
    /** The Hash Map's buckets */
    HashItem **buckets;
    /** A function to hash items into the Hash Map */
    HashFunc hash;
    /** A function to compare keys in the Hash Map */
    CmpFunc cmp;
} HashMap;

/**
 * @brief A default function for hashing chars.
*/
int default_char_hash(char key, int length);

/**
 * @brief A default function for hashing strings.
 */
int default_string_hash(char *key, int length);

/**
 * @brief A default function for hashing ints.
 */
int default_int_hash(int key, int length);

/**
 * @brief A default function for hashing doubles.
 */
int default_double_hash(double key, int length);

/**
 * @brief Allocates a new Hash Map for use.
 * 
 * @param size The number of buckets to put in the Hash Map.
 * @param hashfunc The hashing function to use when inserting.
 * 
 * @returns *HashMap
 */
HashMap *hashmap_new(unsigned int size, HashFunc hashfunc, CmpFunc cmp);

/**
 * @brief Destroys a Hash Map and frees the memory back.
 * 
 * @param map The Hash Map to free.
*/
void hashmap_free(HashMap *map);

/**
 * @brief Inserts a key-value pair into a Hash Map.
 * 
 * @param key The key to insert.
 * @param val The value to be associated with the key.
 * 
 * @returns 1 if the insertion was successful, 0 otherwise.
*/
int insert(Key key, Value val, HashMap *map);

/**
 * @brief Inserts a key-value pair into a Hash Map if the key is not already present.
 *
 * @param key The key to insert.
 * @param val The value to be associated with the key.
 * @param map The Hash Map to insert into.
 *
 * @returns 1 if the insertion was successful, 0 otherwise.
 */
int insert_if_absent(Key key, Value val, HashMap *map);

/**
 * @brief Removes a key (and its associated value) from a Hash Map.
 *
 * @param key The key to remove.
 * @param map The Hash Map to remove from.
 *
 * @returns 1 if the removal was successful, 0 otherwise.
 */
int remove(Key key, HashMap *map);

/**
 * @brief Removes all occurrences a key (and its associated values) from a Hash Map.
 *
 * @param key The key to remove.
 * @param map The Hash Map to remove from.
 *
 * @returns The number of key-value pairs that were removed.
 */
int remove_all(Key key, HashMap *map);

/**
 * @brief Gets the associated value to a key in a Hash Map.
 *
 * @param key The key to look for.
 * @param map The Hash Map to look through.
 *
 * @returns A pointer to found value, NULL if the value does not exist.
 */
Value *get(Key key, HashMap *map);

/**
 * @brief Sets a key's value in a Hash Map.
 *
 * @param key The key to set.
 * @param new_val The new value.
 * @param map The Hash Map.
 *
 * @returns 1 if the value was successfully set, 0 otherwise.
 */
int set(Key key, Value new_val, HashMap *map);

/**
 * @brief Checks for a given key in a Hash Map.
 *
 * @param key The key to look for.
 * @param map The Hash Map to look through.
 *
 * @returns 1 if the key is in the Hash Map, 0 otherwise.
 */
int contains(Key key, HashMap *map);

/**
 * @brief Checks if a Hash Map is empty.
 *
 * @param map The Hash Map to evaluate.
 *
 * @returns 1 if the Hash Map is empty, 0 otherwise.
 */
int empty(HashMap *map);

/**
 * @brief Removes all key-value pairs from a Hash Map.
 *\
 * @param map The Hash Map to clear.
 */
void clear(HashMap *map);

#endif