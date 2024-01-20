/**
 * @file node.c
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A general Node definition.
 * 
 */

#include "node.h"
#include <stdlib.h>

Node *node_new(Item value) {
    Node *node = malloc(sizeof(Node));
    if (!node) return NULL;

    node->value = value;
    node->next = NULL;

    return node;
}

void node_free(Node *node) {
    free(node);
}