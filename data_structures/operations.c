#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "queue.h"
#include "stack.h"
#include "list.h"

L* createlist(int arr[], int size) {

    L* list = (L*)malloc(sizeof(L));
    list->head = malloc(sizeof(N));

    list->head->key = 0;
    list->head->next = list->head;
    list->head->prev = list->head;

    list->size = size;
    for (int i = 0; i < list->size; i++) {
        N* node = (N*)malloc(sizeof(N));
        node->key = arr[i];
        insert(list, node);
    }
    return list;
}

int insert(L* list, N* node) {

    node->next = list->head->next;
    list->head->next = node;
    node->prev = list->head;
    node->next->prev = node;
    if (list->head->next == list->head) {
        return 0;
    }
    return 1;
}

int isEmpty(L* list)
{
    if (list->head->next == list->head) {
        return 1;
    }
    else {
        return 0;
    }
}

N* search(L* list, int key) {
    N* node = malloc(sizeof(N));
    node = list->head->next;
    if (node != NULL) {
        while (node != list->head && node->key != key) {
            node = node->next;
        }
        return node;
    }
    else {
        return NULL;
    }
}

N* delete(L* list, N* node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    else {
        list->head = node->next;
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }
    }
    return node;
}

N* maximum(L* list) {
    N* current = malloc(sizeof(N));
    N* max = malloc(sizeof(N));
    current = list->head->next;
    max = list->head->next;
    while (current != list->head && max != list->head) {
        if (current->key > max->key) {
            max = current;
        }
        current = current->next;
    }
    return max;
}

N* minimum(L* list) {
    N* current = malloc(sizeof(N));
    N* min = malloc(sizeof(N));
    current = list->head->next;
    min = list->head->next;
    while (current != list->head && min != list->head) {
        if (current->key < min->key) {
            min = current;
        }
        current = current->next;
    }
    return min;
}

N* successor(L* list, N* node) {
    N* successor = maximum(list);
    if (node != successor)
    {
        N* current = list->head->next;
        while (current != list->head) {
            if (current->key > node->key && current->key < successor->key) {
                successor = current;
            }
            current = current->next;
        }
        return successor;
    }
    else {
        return NULL;
    }
}

N* predecessor(L* list, N* node) {

    N* predecessor = minimum(list);
    if (node != predecessor)
    {
        N* current = list->head->next;
        while (current != list->head) {
            if (current->key < node->key && current->key> predecessor->key) {
                predecessor = current;
            }
            current = current->next;
        }
        return predecessor;
    }
    else {
        return NULL;
    }
}

void createStack(S* stack) {
    stack->top = -1;
}

void push(S* stack, int key) {
    stack->top++;
    stack->data[stack->top] = key;
}

int pop(S* stack) {
    int value = stack->data[stack->top];
    if (stack != NULL) {
        stack->top = stack->top--;
    }
    return value;
}

void createQueue(Q* queue) {
    queue->head = 0;
    queue->tail = 1;
    queue->size = 0;
}

void enqueue(Q* queue, int key) {
    if (queue->tail == queue->head) {
        printf("overflow");
    }
    else
    {
        if (queue->tail > queue->size) {
            queue->tail = 0;
        }
        queue->data[queue->tail++] = key;
        queue->size++;
    }
}

int dequeue(Q* queue) {
    int key = queue->data[queue->head];
    if (queue->head = queue->size) {
        queue->head = 0;
    }
    else {
        queue->size = queue->size--;
        queue->head = queue->head++;
    }
    return key;
}