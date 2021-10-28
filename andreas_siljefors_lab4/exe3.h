#pragma once

//operations
Graph_scc* createGraph_exe3(int n);;
void addEdge(Graph_scc* graph, int u, int v);
void DFS(Graph_scc* graph);
int DFS_transpose(Graph_scc* graph);
void DFS_visit(Graph_scc* graph, int u);
void DFS_visit_transpose(Graph_scc* G, int u);
Graph_scc* transposeGraph(Graph_scc* graph);

//list
SccList* createSccList();
int ScclistInsert(SccList* list, SccNode* node);
SccList* adjList(Graph_scc* graph, int u);

//tests
Graph_scc* initializeGraph();
void testExe3();
