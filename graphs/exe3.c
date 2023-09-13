#include <stdio.h>
#include <stdlib.h>
#include "structs_exe3.h"
#include "exe3.h"

int white = 1;
int grey = 2;
int black = 3;
int time = 0;
int scc = 0;


//graph

Graph_scc* createGraph_exe3(int n) {

	Graph_scc* graph = (Graph_scc*)malloc(sizeof(Graph_scc));
	graph->matrix = malloc(n * sizeof(int));
	graph->n = n;

	for (int i = 0; i < n; i++) {
		graph->matrix[i] = malloc(n * sizeof(int));
		graph->color[i] = &white;
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			graph->matrix[x][y] = 0;
		}
	}
	return graph;
}

Graph_scc* transposeGraph(Graph_scc* graph)
{
	Graph_scc* transpose = createGraph_exe3(graph->n);

	for (int x = 0; x < transpose->n; x++) {
		for (int y = 0; y < transpose->n; y++) {
			if (graph->matrix[x][y] == 1) {
				transpose->matrix[y][x] = graph->matrix[x][y];
				transpose->timeD[y] = graph->timeD[x];
				transpose->timeF[y] = graph->timeF[x];
				transpose->color[y] = graph->color[x];
			}
		}
	}
	return transpose;
}

void addEdge(Graph_scc* graph, int src, int dest) {
	graph->matrix[src][dest] = 1;
}

//list
SccList* createSccList() {
	SccList* list = (SccList*)malloc(sizeof(SccList));
	list->head = (SccNode*)malloc(sizeof(SccNode));
	list->head->k = INT_MAX;
	list->head->next = list->head;
	list->head->prev = list->head;

	list->n = 1;

	return list;
}

int ScclistInsert(SccList* list, SccNode* node) {
	node->next = list->head->next;
	list->head->next = node;
	node->prev = list->head;
	node->next->prev = node;
	if (list->head->next == list->head) {
		return 0;
	}
	return 1;
}

SccList* adjList(Graph_scc* graph, int u) {
	SccList* list = createSccList();
	for (int i = 0; i < graph->n; i++) {
		if (graph->matrix[u][i] != 0) {
			SccNode* node = malloc(sizeof(SccNode));
			node->k = i;
			ScclistInsert(list, node);
			list->n = list->n++;
		}
	}
	return list;
}

//DFS

void DFS(Graph_scc* graph) {
	for (int i = 0; i < graph->n; i++) {
		if (graph->color[i] == &white) {
			DFS_visit(graph, i);
		}
	}
}

int DFS_transpose(Graph_scc* graph) {
	scc = 0;
	for (int i = 0; i < graph->n; i++) {
		graph->color[i] = &white;
	}
	scc++;
	for (int i = time; i > 0; i--) {
		for (int j = 0; j < graph->n; j++) {
			if (graph->timeF[j] == &i) {
				if (graph->color[j] == &white) {
					scc++;
					DFS_visit_transpose(graph, j);
				}
			}
		}
	}
	return scc;
}

void DFS_visit(Graph_scc* graph, int u) {
	time = time + 1;
	graph->color[u] = &grey; // vertex u has been discovered 
	graph->timeD[u] = &time;
	SccList* list = adjList(graph, u);
	SccNode* temp = list->head->next;
	while (temp != list->head) {
		if (graph->color[temp->k] == &white) {
			DFS_visit(graph, temp->k);
		}
		temp = temp->next;
	}
	graph->color[u] = &black; // vertex u has finished (black)
	time = time + 1;
	graph->timeF[u] = &time;
}

void DFS_visit_transpose(Graph_scc* graph, int u) {
	graph->color[u] = &grey;
	SccList* list = adjList(graph, u);
	SccNode* temp = list->head->next;
	while (temp != list->head) {
		if (graph->color[temp->k] == &white) {
			DFS_visit_transpose(graph, temp->k);
		}
		temp = temp->next;
	}
	graph->color[u] = &black;
}