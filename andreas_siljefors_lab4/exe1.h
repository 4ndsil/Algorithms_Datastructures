#pragma once
//operations
AdjNode* newNode(int dest);
Graph* createGraph(int n);
AdjList* createList(int size);
void addUndirectedEdges(Graph* graph, AdjNode* v, AdjNode* u);
void addDirectedEdges(Graph* graph, AdjNode* v, AdjNode* u);
int getNumVertices(Graph* graph);
int getNumEdges(Graph* graph);
AdjList* getNeighbors(Graph* graph, AdjNode* node);
AdjList* getInNeighbors(Graph* graph, AdjNode* node);
AdjList* getOutNeighbors(Graph* graph, AdjNode* node);
int hasEdge(Graph* graph, AdjNode* v, AdjNode* u);
int getNumEdges(Graph* graph);
int isUndirected(Graph* graph);

//tests
void testNeighbors(Graph* graph);
void testInNeighbors(Graph* graph);
void testOutNeighbors(Graph* graph);
void testHasEdge(Graph* graph);
Graph* testDirectedGraph();
Graph* testUnDirectedGraph();