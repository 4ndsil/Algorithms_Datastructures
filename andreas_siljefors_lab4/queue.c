#include <stdio.h>
#include <stdlib.h>
#include "structs_exe1_2.h"
#include "queue.h"

Queue* createQueue() {
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	QueueNode* head = malloc(sizeof(QueueNode));
	Edge* edge = malloc(sizeof(Edge));
	edge->x = INT_MAX;
	edge->y = INT_MAX;
	head->edge = edge;
	head->next = head;
	head->prev = head;
	queue->head = head;
	return queue;
}

int queueEmpty(Queue* queue) {
	if (queue->head->next == queue->head)
		return 1;
	else
		return 0;
}

void enqueue(Queue* queue, QueueNode* node) {
	node->next = queue->head->next;
	queue->head->next = node;
	node->prev = queue->head;
	node->next->prev = node;
}

QueueNode* dequeue(Queue* queue) {
	QueueNode* temp = queue->head->prev;
	if (queue->head->next != queue->head) {
		queue->head->prev = temp->prev;
		temp->prev->next = queue->head;
	}
	return temp;
}