/**
 * @file hashmap.h
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A key-value Hash Map.
 *
 */

#include "hashmap.h"
#include <stdlib.h>
#include <math.h>

int default_char_hash(char key, int length) {
    return ((int) key) % length;
}

int default_string_hash(char *key, int length) {
    long int hash = 0;
    int p = 2;
    int n = 0;

    while (key[n]) {
        hash += ((int) key[n]) * pow(p, n);
        n++;
    }

    return hash % length;
}

int default_int_hash(int key, int length) {
    return abs(key) % length;
}

int default_double_hash(double key, int length) {
    return abs((int) key) % length;
}

HashMap *hashmap_new(unsigned int size, HashFunc hashfunc, CmpFunc cmp) {
    HashMap *map = malloc(sizeof(HashMap));
    if (!map) return NULL;

    map->buckets = calloc(size, sizeof(HashItem*));
    if (!map->buckets) {
        free(map);
        return NULL;
    }

    map->size = size;
    map->item_count = 0;
    map->hash = hashfunc;
    map->cmp = cmp;

    return map;
}

void hashmap_free(HashMap *map) {
    for (int i = 0; i < map->size; i++) {
        HashItem *current = map->buckets[i];
        HashItem *prev;
        while (current) {
            prev = current;
            current = current->next;
            free(prev);
        }
    }
}

int insert(Key key, Value val, HashMap *map) {
    HashItem *entry = malloc(sizeof(HashItem));
    if (!entry) return FAILURE;

    int loc = map->hash(key, map->size);

    entry->key = key;
    entry->value = val;
    entry->next = map->buckets[loc];
    map->buckets[loc] = entry;
    map->item_count++;

    return SUCCESS;
}

int insert_if_absent(Key key, Value val, HashMap *map) {
    HashItem *entry = malloc(sizeof(HashItem));
    if (!entry)
        return FAILURE;

    int loc = map->hash(key, map->size);

    HashItem *current = map->buckets[loc];

    while (current && current->next) {
        if (cmp(key, current->key) == 0) return FAILURE;
        current = current->next;
    }

    entry->key = key;
    entry->value = val;
    entry->next = map->buckets[loc];
    map->buckets[loc] = entry;
    map->item_count++;

    return SUCCESS;
}

int remove(Key key, HashMap *map) {
    int loc = map->hash(key, map->size);

    HashItem *current = map->buckets[loc];
    HashItem *prev;

    while (current && current->next)
    {
        if (cmp(key, current->key) == 0) {
            prev->next = current->next;
            free(current);
            map->item_count--;
            return SUCCESS;
        }
        prev = current;
        current = current->next;
    }

    return FAILURE;
}

int remove_all(Key key, HashMap *map) {
    int loc = map->hash(key, map->size);

    HashItem *current = map->buckets[loc];
    HashItem *prev;

    int begin_count = map->item_count;

    while (current && current->next)
    {
        if (cmp(key, current->key) == 0)
        {
            prev->next = current->next;
            free(current);
            map->item_count--;
        }
        prev = current;
        current = current->next;
    }

    return begin_count - map->item_count;
}

Value *get(Key key, HashMap *map) {
    int loc = map->hash(key, map->size);

    HashItem *current = map->buckets[loc];

    while (current && current->next) {
        if (map->cmp(key, current->key) == 0) return &(current->value);
    }

    return NULL;
}