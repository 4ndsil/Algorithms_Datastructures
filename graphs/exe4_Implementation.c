#include <stdio.h>
#include <stdlib.h>
#include "structs_exe4.h"
#include "exe4.h"

void testExe4_1() {

	//int n = 8;
	int n = 3;
	Graph_sssp* graph = createGraph_exe4(n);

	//setting values for source, destination, weight (x,y,w)

	graph->matrix[0][1] = 1;
	graph->matrix[1][2] = 1;
	graph->matrix[1][0] = -2;
	/*graph->matrix[0][1] = 2;
	graph->matrix[1][2] = 3;
	graph->matrix[2][3] = 2;
	graph->matrix[1][6] = -1;
	graph->matrix[0][5] = 4;
	graph->matrix[5][6] = 2;
	graph->matrix[6][3] = 3;
	graph->matrix[3][4] = 5;
	graph->matrix[6][7] = 6;
	graph->matrix[7][4] = 2;*/

	int result = Bellman_Ford(graph, 0);

	if (result == 0) {
		printf("\n The graph contains a negative cycle, no solution exists.");
		free(graph);
	}
	else {
		for (int i = 0; i < graph->n; i++) {
			int d = getDistance(i);
			if (d != INT_MAX) {
				printf("\n The distance from source to vertex %d is %d,\n", i, d);
			}
		}
		free(graph);
	}	
}

void testExe4_2() {

	//int n = 10;
	int n = 3;
	Graph_sssp* graph = createGraph_exe4(n);

	//setting values for source, destination, weight (x,y,w)

	/*graph->matrix[1][2] = 2;
	graph->matrix[2][3] = 3;
	graph->matrix[3][4] = 4;
	graph->matrix[4][5] = 5;
	graph->matrix[4][5] = -1;
	graph->matrix[5][6] = -2;
	graph->matrix[6][4] = -2;
	graph->matrix[3][6] = 6;*/

	int result = Bellman_Ford(graph, 1);

	if (result == 0) {
		printf("\n The graph contains a negative cycle, no solution exists.");
		free(graph);
	}
	else {
		for (int i = 0; i < graph->n; i++) {
			int d = getDistance(i);
			if (d != INT_MAX) {
				printf("\n The distance from source to vertex %d is %d,\n", i, d);
			}
		}
		free(graph);
	}
	
}