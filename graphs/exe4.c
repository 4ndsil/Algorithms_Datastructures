#include <stdio.h>
#include <stdlib.h>
#include "structs_exe4.h"
#include "exe4.h"

int distance[20];
int max = 10000;

//graph
Graph_sssp* createGraph_exe4(int n) {

	Graph_sssp* graph = (Graph_sssp*)malloc(sizeof(Graph_sssp));
	graph->matrix = malloc(n * sizeof(int));
	graph->parent[n] = malloc(n* sizeof(int));

	graph->n = n;

	for (int i = 0; i < n; i++) {
		graph->matrix[i] = malloc(n * sizeof(int));
		graph->parent[i] = malloc(sizeof(int));
	}

	for (int x = 0; x < graph->n; x++) {
		for (int y = 0; y < graph->n; y++) {
			graph->matrix[x][y] = max;

		}
	}
	return graph;
}

//Bellman Ford

void relax(Graph_sssp* graph, int src, int dest, int w) {

	if (distance[dest] > distance[src] + w) {
		distance[dest] = distance[src] + w;
		graph->parent[dest] = &src;
	}
}

void initialize_Single_Source(Graph_sssp* graph, int u) {
	for (int i = 0; i < graph->n; i++) {
		distance[i] = INT_MAX;
		(*graph->parent[i]) = max;
	}
	distance[u] = 0;
}

int Bellman_Ford(Graph_sssp* graph, int u) {

	initialize_Single_Source(graph, u);

	for (int i = 0; i < graph->n - 1; i++) {
		for (int x = 0; x < graph->n; x++) {
			for (int y = 0; y < graph->n; y++) {
				if (graph->matrix[x][y] != max) {

					relax(graph, x, y, graph->matrix[x][y]);

				}
			}
		}
		for (int x = 0; x < graph->n; x++) {
			for (int y = 0; y < graph->n; y++) {
				if (graph->matrix[x][y] != max) {
					if (distance[y] > (distance[x] + graph->matrix[x][y])) {
						return 0;

					}
				}
			}
		}
	}
	return 1;
}

int getDistance(int i) {

	return distance[i];
}