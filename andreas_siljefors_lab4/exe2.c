#include <stdio.h>
#include <stdlib.h>
#include "structs_exe1_2.h"
#include "exe2.h"
#include "queue.h"

int initial = 1;
int waiting = 2;
int visited = 3;

Graph* createGraph_exe2() {

	int n = 10;

	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->matrix = malloc(n * sizeof(int));
	graph->state[n][n] = malloc(sizeof(int));
	graph->n = n;

	for (int i = 0; i < n; i++) {
		graph->matrix[i] = malloc(n * sizeof(int));
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			graph->state[x][y] = &initial;
			graph->matrix[x][y] = 0;
		}
	}

	return graph;
}

int isValid(Graph* graph, int x, int y) {
	if (graph->matrix[x][y] != 0) {
		return 0;
	}
	return 1;
}

Edge* BFS_exe2(Graph* graph, int srcx, int srcy, int destx, int desty) {
	QueueNode* tempNode = (QueueNode*)malloc(sizeof(QueueNode));
	Edge* edge1 = (Edge*)malloc(sizeof(Edge));
	edge1->x = srcx;
	edge1->y = srcy;
	Queue* queue = createQueue();
	edge1->d = 0;
	tempNode->edge = edge1;
	enqueue(queue, tempNode);

	while (!queueEmpty(queue))
	{
		QueueNode* current = dequeue(queue);
		Edge* temp = current->edge;
		graph->state[temp->x][temp->y] = &visited;

		if (temp->x == destx && temp->y == desty) {
			return temp;
			break;
		}

		if (temp->x != graph->n - 1) {
			if (isValid(graph, temp->x + 1, temp->y) && graph->state[temp->x + 1][temp->y] == &initial) {
				QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
				Edge* edge = (Edge*)malloc(sizeof(Edge));
				edge->parent = (Edge*)malloc(sizeof(Edge));
				edge->x = temp->x + 1;
				edge->y = temp->y;
				edge->d = temp->d + 1;
				edge->parent = temp;
				node->edge = edge;
				graph->state[temp->x + 1][temp->y] = &waiting;
				enqueue(queue, node);
			}
		}
		if (temp->x != 0) {
			if (isValid(graph, temp->x - 1, temp->y) && graph->state[temp->x - 1][temp->y] == &initial) {
				QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
				Edge* edge = (Edge*)malloc(sizeof(Edge));
				edge->parent = (Edge*)malloc(sizeof(Edge));
				edge->x = temp->x - 1;
				edge->y = temp->y;
				edge->d = temp->d + 1;
				edge->parent = temp;
				node->edge = edge;
				graph->state[temp->x - 1][temp->y] = &waiting;
				enqueue(queue, node);
			}
		}
		if (temp->y != graph->n - 1) {
			if (isValid(graph, temp->x, temp->y + 1) && graph->state[temp->x][temp->y + 1] == &initial) {
				QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
				Edge* edge = (Edge*)malloc(sizeof(Edge));
				edge->parent = (Edge*)malloc(sizeof(Edge));
				edge->x = temp->x;
				edge->y = temp->y + 1;
				edge->d = temp->d + 1;
				edge->parent = temp;
				node->edge = edge;
				graph->state[temp->x][temp->y + 1] = &waiting;
				enqueue(queue, node);
			}
		}
		if (temp->x != 0) {
			if (isValid(graph, temp->x, temp->y - 1) && graph->state[temp->x][temp->y - 1] == &initial) {
				QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
				Edge* edge = (Edge*)malloc(sizeof(Edge));
				edge->parent = (Edge*)malloc(sizeof(Edge));
				edge->x = temp->x;
				edge->y = temp->y - 1;
				edge->d = temp->d + 1;
				edge->parent = temp;
				node->edge = edge;
				graph->state[temp->x][temp->y - 1] = &waiting;
				enqueue(queue, node);
			}
		}
	}
	return 0;
}