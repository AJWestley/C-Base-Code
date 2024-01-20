/**
 * @file linked_list.c
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A dynamic list of linked nodes.
 * 
 */

#include "linked_list.h"
#include <stdlib.h>
#include <math.h>

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

LinkedList *linked_list_new() {
    LinkedList *list = malloc(sizeof(LinkedList));
    if (!list) return NULL;

    list->root = NULL;
    list->size = 0;

    return list;
}

void linked_list_free(LinkedList *list) {
    clear(list);
    free(list);
}

int add_front(Item item, LinkedList *list) {
    Node *node = node_new(item);
    if (!node) return FAILURE;

    node->next = list->root;
    list->root = node;
    list->size++;

    return SUCCESS;
}

int add_back(Item item, LinkedList *list) {
    Node *node = node_new(item);
    if (!node) return FAILURE;

    if (list->size == 0) {
        list->root = node;
    }
    else {
        Node *current = list->root;
        while (current->next) {
            current = current->next;
        }
        current->next = node;
    }

    list->size++;

    return SUCCESS;
}

int remove_front(LinkedList *list) {
    if (list->size == 0) return FAILURE;
    Node *node = list->root;

    list->root = list->root->next;
    node_free(node);

    list->size--;

    return SUCCESS;
}

int remove_back(LinkedList *list) {
    if (list->size == 0) return FAILURE;

    if (list->size == 1) {
        node_free(list->root);
        list->root = NULL;
    }
    else {
        Node *current = list->root;
        Node *prev;
        while (current->next) {
            prev = current;
            current = current->next;
        }
        node_free(current);
        prev->next = NULL;
    }

    list->size--;

    return SUCCESS;
}

Node *get_front(LinkedList *list) {
    return list->root;
}

Node *get_back(LinkedList *list) {
    if (list->size == 0) return NULL;
    
    Node *current = list->root;
    
    while (current->next) {
        current = current->next;
    }

    return current;
}

void clear(LinkedList *list) {
    Node *prev;
    while (list->root) {
        prev = list->root;
        list->root = list->root->next;
        node_free(prev);
    }
    list->size = 0;
}

int contains(Item item, LinkedList *list) {
    if (list->size == 0) return FALSE;

    Node *current = list->root;
    double err = 1 / 1048576;

    while (current->next) {
        if (fabs(current->value - item) < err) return TRUE;
        current = current->next;
    }

    return FALSE;
}

int empty(LinkedList *list) {
    return list->size == 0 ? TRUE : FALSE;
}