/**
 * @file queue.c
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A dynamic double-ended queue of linked nodes.
 *
 */

#include "queue.h"
#include <stdlib.h>
#include <math.h>

Queue *queue_new() {
    Queue *queue = malloc(sizeof(Queue));
    if (!queue) return NULL;

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

void queue_free(Queue *queue) {
    clear(queue);
    free(queue);
}

int enqueue(Item item, Queue *queue) {
    queue->tail->next = node_new(item);
    if (!queue->tail->next) return FAILURE;

    queue->tail = queue->tail->next;
    queue->size++;

    if (queue->size == 1) queue->head = queue->tail;

    return SUCCESS;
}

int dequeue(Queue *queue) {
    if (queue->size == 0) return FAILURE;

    Node *node = queue->head;
    queue->head = queue->head->next;
    node_free(node);

    queue->size--;

    if (queue->size == 0) queue->tail = NULL;

    return SUCCESS;
}

Node *get_front(Queue *queue) {
    return queue->head;
}

void clear(Queue *queue) {
    Node *prev;
    while (queue->head) {
        prev = queue->head;
        queue->head = queue->head->next;
        node_free(prev);
    }
    queue->tail = NULL;
    queue->size = 0;
}

int contains(Item item, Queue *queue) {
    if (queue->size == 0) return FALSE;

    Node *current = queue->head;
    double err = 1 / 1048576;

    while (current->next) {
        if (fabs(current->value - item) < err) return TRUE;
        current = current->next;
    }

    return FALSE;
}

int empty(Queue *queue) {
    return queue->size == 0 ? TRUE : FALSE;
}