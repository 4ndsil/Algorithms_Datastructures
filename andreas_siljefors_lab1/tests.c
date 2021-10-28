#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "list.h"
#include "queue.h"
#include "stack.h"

void testDelete(L* list, int key) {
    N* node = malloc(sizeof(N));
    node = delete(list, search(list, key));

    if (node == NULL) {
        printf("error");
    }
    else {
        free(node);
        printf("\nnode %d was deleted", key);
    }
}

int testMax(L* list, int key) {
    N* searched = (N*)malloc(sizeof(N));
    N* returnValue = (N*)malloc(sizeof(N));
    searched = search(list, key);
    returnValue = maximum(list);
    if (returnValue->key == key) {
        printf("\nsuccess");
        printf("\nmaximum() returned %d, expected value %d", returnValue->key, key);

        return 1;

    }
    else {
        printf("\nfail");
        printf("\nmaximum() returned %d, expected value %d", returnValue->key, key);

        return 0;
    }
}

int testMin(L* list, int key) {
    N* searched = (N*)malloc(sizeof(N));
    N* returnValue = (N*)malloc(sizeof(N));
    searched = search(list, key);
    returnValue = minimum(list);
    if (returnValue->key == key) {
        printf("\nsuccess");
        printf("\nminimum() returned %d, expected value %d", returnValue->key, key);

        return 1;
    }
    else {
        printf("\nfail");
        printf("\nminimum() returned %d, expected value %d", returnValue->key, key);

        return 0;
    }
}

int testSucc(L* list, int key) {
    N* searched = (N*)malloc(sizeof(N));
    N* returnValue = (N*)malloc(sizeof(N));
    searched = search(list, key);
    returnValue = successor(list, searched);
    if (returnValue != NULL) {
        if (returnValue->key > searched->key) {
            printf("\nsuccess");
            printf("\nsuccessor of %d is %d", key, returnValue->key);

            return 1;
        }
    }
    printf("\nfail");
    printf("\nnode %d is the largest", searched->key);

    return 0;

}


int testPre(L* list, int key) {
    N* searched = (N*)malloc(sizeof(N));
    N* returnValue = (N*)malloc(sizeof(N));
    searched = search(list, key);
    returnValue = predecessor(list, searched);
    if (returnValue != NULL) {
        if (returnValue->key < searched->key) {
            printf("\nsuccess");
            printf("\npredecessor of %d is %d", key, returnValue->key);

            return 1;
        }
    }

    printf("\nfail");
    printf("\nnode %d is the smallest", searched->key);

    return 0;

}

int testPreMax(L* list1, L* list2) {

    N* max = malloc(sizeof(N));
    N* pre = malloc(sizeof(N));
    max = maximum(list1);
    pre = predecessor(list2, max);
    if (pre != NULL) {
        if (pre->key < max->key) {
            printf("\nsuccess");
            printf("\npredecessor of %d is %d", max->key, pre->key);

            return 1;
        }
    }
    printf("\nfail");
    printf("\nnode %d is the smallest node", max->key);

    return 0;
}


S* testStack(S* stack) {
    if (stack != NULL) {
        push(stack, 9);
        push(stack, 6);
        push(stack, 0);
        push(stack, 9);
        push(stack, 0);
        push(stack, 7);
    }
    printf("\nstack");
    for (int i = 0; i < 6; i++) {
        printf("\n%d", stack->data[i]);
    }
    return stack;
}

int testPop(S* stack) {
    int expected = 7;
    int returnValue = pop(stack);
    if (returnValue == expected) {
        printf("\nsuccess");
        printf("\npop expected %d, deleted value %d", expected, returnValue);
        return 1;
    }
    else {
        printf("\nfail");
        printf("\npop expected %d, deleted value %d", expected, returnValue);
        return 0;
    }
}

Q* testEnqueue(Q* queue) {
    if (queue != NULL) {
        enqueue(queue, 9);
        enqueue(queue, 6);
        enqueue(queue, 0);
        enqueue(queue, 9);
        enqueue(queue, 0);
        enqueue(queue, 7);
    }
    printf("\nqueue");
    for (int i = 0; i < 6; i++) {
        printf("\n%d", queue->data[i]);
    }
    return queue;
}

int testDequeue(Q* queue) {
    int expected = 9;
    int returnValue = dequeue(queue);
    if (returnValue == expected) {
        printf("\nsuccess");
        printf("\ndequeue expected %d, deleted value %d", expected, returnValue);
        return 1;
    }
    else {
        printf("\nfail");
        printf("\ndequeue expected %d, deleted value %d", expected, returnValue);
        return 0;
    }
}