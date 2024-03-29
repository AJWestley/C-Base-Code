/**
 * @file array_list.c
 *
 * @author AJ Westley (alexanderjwestley@gmail.com)
 *
 * @brief A dynamic array operating like Python's 'Lists'.
 * 
 */

#include "array_list.h"
#include <stdlib.h>
#include <math.h>

ArrayList *array_list_new(unsigned int size) {
    ArrayList *list;

    if (size == 0) size = 4;

    list = malloc(sizeof(ArrayList));
    if (!list) return NULL;

    list->items = malloc(size * sizeof(Item));
    if (!list->items) {
        free(list);
        return NULL;
    }

    list->length = 0;
    list->_allocated = size;

    return list;
}

void array_list_free(ArrayList *list) {
    free(list->items);
    free(list);
}

int insert(int index, Item item, ArrayList *list) {
    if (list->length == list->_allocated) {
        int successful = resize(2 * list->length, list);
        if (!successful) return FAILURE;
    }

    if (index > list->length) return FAILURE;

    list->length++;

    for (int i = index; i < list->length; i++) {
        list->items[i+1] = list->items[i];
    }

    list->items[index] = item;

    return SUCCESS;
}

int append(Item item, ArrayList *list) {
    return insert(list->length, item, list);
}

int remove_index(int index, ArrayList *list) {
    if (index >= list->length) return FAILURE;

    for (int i = index; i < list->length; i++) {
        list->items[i] = list->items[i+1];
    }
    list->length--;

    return SUCCESS;
}

int remove(Item value, ArrayList *list) {
    int index = find(value, list);

    if (index == -1) return FAILURE;

    return remove(index, list);
}

Item get(int index, ArrayList *list) {
    return list->items[index];
}

void clear(ArrayList *list) {
    list->length = 0;
}

int find(Item item, ArrayList *list) {
    double err = 1 / 1048576;
    for (int i = 0; i < list->length; i++) {
        if (fabs(list->items[i] - item) < err) return i;
    }
    return -1;
}

int contains(Item item, ArrayList *list) {
    return find(item, list) != -1;
}

int count(Item value, ArrayList *list) {
    double err = 1 / 1048576;
    int cnt = 0;
    for (int i = 0; i < list->length; i++) {
        if (fabs(list->items[i] - value) < err) cnt++;
    }
    return cnt;
}

int empty(ArrayList *list) {
    return list->length == 0;
}

int resize(int new_size, ArrayList *list) {
    if (new_size < list->length) return FAILURE;

    int *items = realloc(list->items, sizeof(int) * new_size);

    if (!items) return FAILURE;

    list->items = items;
    list->_allocated = new_size;

    return SUCCESS;
}

int compress(ArrayList *list) {
    return resize(list->length, list);
}

void reverse(ArrayList *list) {
    int j, mid = list->length / 2;
    Item tmp;

    for (int i = 0; i < mid; i++) {
        j = list->length - i - 1;
        tmp = list->items[i];
        list->items[i] = list->items[j];
        list->items[j] = tmp;
    }
}

int insertion_sort(ArrayList *list) {
    for (int i = 1; i < list->length; i++) {
        int j = i - 1;
        while (j >= 0 && get(i, list) < get(j, list)) {
            list->items[j+1] = get(j, list);
            j--;
        }
        list->items[j+1] = get(i, list);
    }
    return SUCCESS;
}

int merge_sort(ArrayList *list) {
    if (list->length <= 1) return SUCCESS;

    int mid = (int) (list->length / 2);

    ArrayList *L = array_list_new(mid);
    if (!L) return FAILURE;
    
    ArrayList *R = array_list_new(list->length - mid);
    if (!R) return FAILURE;

    for (int i = 0; i < L->length; i++) {
        L->items[i] = list->items[i];
    }
    for (int i = 0; i < R->length; i++) {
        R->items[i] = list->items[i+mid];
    }
    
    if (!merge_sort(L)) return FAILURE;
    if (!merge_sort(R)) return FAILURE;

    int i = 0, j = 0, k = 0;

    while (i < L->length && j < R->length) {
        if (get(i, L) <= get(j, R)) {
            list->items[k] = get(i, L);
            i++;
        }
        else {
            list->items[k] = get(j, R);
            j++;
        }
        k++;
    }

    while (i < L->length) {
        list->items[k] = get(i, L);
        i++;
        k++;
    }

    while (j < R->length) {
        list->items[k] = get(j, R);
        j++;
        k++;
    }

    array_list_free(L);
    array_list_free(R);

    return SUCCESS;
}

int quick_sort(ArrayList *list) {
    qsort(list->items, list->length, sizeof(Item), cmpfunc);
    return SUCCESS;
}

int cmpfunc(void *a, void *b) {
   return ( *(Item*)a - *(Item*)b );
}
