#pragma once

//operations
Graph* createGraph_exe2();
Edge* BFS_exe2(Graph* graph, int srcx, int srxy, int destx, int desty);
int isValid(Graph* graph, int x, int y);

//tests
void testExe2();
