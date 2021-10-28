#include <stdio.h>
#include <stdlib.h>
#include "structs_exe1_2.h"
#include "exe2.h"

int isVisited = 3;

void testExe2() {
	Graph* graph = createGraph_exe2();

	int x[16] = { 4,4,4,4,4,5,6,7,8,4,4,4,1,2,3,4 };
	int y[16] = { 0,1,2,3,4,4,4,4,4,5,6,7,8,8,8,8 };

	for (int i = 0; i < 16; i++) {
		graph->matrix[x[i]][y[i]] = 1;
		graph->state[x[i]][y[i]] = &isVisited;
	}

	Edge* temp = BFS_exe2(graph, 0, 0, 5, 0);

	printf("\n Distance: %d", temp->d);
	while (temp->d > 0) {
		printf("\n %d, %d", temp->parent->x + 1, temp->parent->y + 1);
		temp->parent = temp->parent->parent;
		temp->d--;
	}

	free(graph);
	free(temp);
}