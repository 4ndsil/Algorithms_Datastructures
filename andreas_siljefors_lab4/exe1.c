#include <stdio.h>
#include <stdlib.h>
#include "structs_exe1_2.h"
#include "exe1.h"

//list
AdjList* createList(int size) {

    AdjList* list = (AdjList*)malloc(sizeof(AdjList));
    list->head = (AdjNode*)malloc(sizeof(AdjNode));
    list->head->k = INT_MAX;
    list->head->next = list->head;
    list->head->prev = list->head;

    list->size = size;

    return list;
}

void insert(AdjList* list, AdjNode* node) {
    node->next = list->head->next;
    list->head->next->prev = node;
    list->head->next = node;
}

AdjNode* newNode(int k)
{
    AdjNode* node = (AdjNode*)malloc(sizeof(AdjNode));
    node->k = k;
    return node;
}

//graph
Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n = n;
    graph->matrix = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        graph->matrix[i] = malloc(n * sizeof(int));

    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            graph->matrix[x][y] = 0;

        }
    }
    return graph;
}

int getNumVertices(Graph* graph) {
    return graph->n;
}

int getNumEdges(Graph* graph) {

    int edges = 0;

    for (int i = 0; i < graph->n; i++) {
        for (int j = 0; j < graph->n; j++) {
            if (graph->matrix[i][j] != 0) {
                edges++;

            }
        }
    }
    if (!isUndirected(graph)) {
        return edges;
    }
    return edges / 2;
}

int isUndirected(Graph* graph) {
    for (int i = 0; i < graph->n; i++) {
        for (int j = 0; j < graph->n; j++) {
            if (graph->matrix[i][j] == 1 && graph->matrix[j][i] == 1) {
                return 1;
            }
        }
    }
    return 0;
}

AdjList* getNeighbors(Graph* graph, AdjNode* node) {
    AdjList* list = createList(1);
    for (int i = 0; i < graph->n; i++) {
        if (i != node->k) {
            if ((graph->matrix[node->k][i] != 0) || (graph->matrix[i][node->k] != 0)) {
                AdjNode* temp = newNode(i);
                insert(list, temp);
                list->size++;
            }
        }
    }
    return list;
}

AdjList* getInNeighbors(Graph* graph, AdjNode* node) {
    AdjList* list = createList(1);
    for (int i = 0; i < graph->n; i++) {
        if (i != node->k) {
            if (graph->matrix[i][node->k] != 0) {
                AdjNode* temp = newNode(i);
                insert(list, temp);
                list->size++;
            }
        }
    }
    return list;
}

AdjList* getOutNeighbors(Graph* graph, AdjNode* node) {
    AdjList* list = createList(1);
    for (int i = 0; i < graph->n; i++) {
        if (i != node->k) {
            if (graph->matrix[node->k][i] != 0) {
                AdjNode* temp = newNode(i);
                insert(list, temp);
                list->size++;
            }
        }
    }
    return list;
}


void addDirectedEdges(Graph* graph, AdjNode* v, AdjNode* u) {
    graph->matrix[v->k][u->k] = 1;
}

void addUndirectedEdges(Graph* graph, AdjNode* v, AdjNode* u) {
    graph->matrix[v->k][u->k] = 1;
    graph->matrix[v->k][u->k] = 1;
}

int hasEdge(Graph* graph, AdjNode* v, AdjNode* u) {
    if (graph->matrix[v->k][u->k] == 1 || graph->matrix[u->k][v->k] == 1) {
        return 1;
    }
    return 0;
}