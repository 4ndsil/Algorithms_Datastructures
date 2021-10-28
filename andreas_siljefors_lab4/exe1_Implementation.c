#include <stdio.h>
#include <stdlib.h>
#include "structs_exe1_2.h"
#include "exe1.h"

void testHasEdge(Graph* graph) {

    AdjNode* v = (AdjNode*)malloc(sizeof(AdjNode));
    v->k = 0;
    AdjNode* u = (AdjNode*)malloc(sizeof(AdjNode));
    u->k = 4;

    int bool = hasEdge(graph, v, u);

    if (bool == 1) {
        printf("\n vertex %d and %d have an edge", v->k, u->k);
    }
    else if (bool == 0) {
        printf("\n vertex %d and %d does not have an edge", v->k, u->k);
    }
    free(v);
    free(u);
}

void testNeighbors(Graph* graph) {
    AdjNode* vertex = (AdjNode*)malloc(sizeof(AdjNode));
    vertex->k = 4;
    AdjList* list = (AdjList*)malloc(sizeof(AdjList));
    list = getNeighbors(graph, vertex);

    AdjNode* node = list->head->next;
    printf("\n Neighbors of vertex %d is: ", vertex->k);
    for (int i = 0; i < list->size; i++) {
        while (node->k != INT_MAX) {
            printf(" %d ", node->k);
            node = node->next;
        }
    }
    free(node);
    free(list);
}
void testInNeighbors(Graph* graph) {
    AdjNode* vertex = (AdjNode*)malloc(sizeof(AdjNode));
    vertex->k = 4;
    AdjList* list = (AdjList*)malloc(sizeof(AdjList));
    list = getInNeighbors(graph, vertex);

    AdjNode* node = list->head->next;
    printf("\n In neighbors of vertex %d is: ", vertex->k);
    for (int i = 0; i < list->size; i++) {
        while (node->k != INT_MAX) {
            printf(" %d ", node->k);
            node = node->next;
        }
    }
    free(vertex);
    free(list);
}
void testOutNeighbors(Graph* graph) {
    AdjNode* vertex = (AdjNode*)malloc(sizeof(AdjNode));
    vertex->k = 4;
    AdjList* list = (AdjList*)malloc(sizeof(AdjList));
    list = getOutNeighbors(graph, vertex);

    AdjNode* node = list->head->next;
    printf("\n Out neighbors of vertex %d is: ", vertex->k);
    for (int i = 0; i < list->size; i++) {
        while (node->k != INT_MAX) {
            printf(" %d ", node->k);
            node = node->next;
        }
    }
    free(vertex);
    free(list);
}

Graph* testDirectedGraph() {
    Edge edges[] = { {0,4}, {1,2}, {3,1}, {4,2}, {2,0},{0,5}, {3,5} };
    int n = sizeof(edges) / sizeof(edges[0]);
    Graph* graph = createGraph(n);

    for (int i = 0; i < n; i++) {
        int src = edges[i].x;
        int dest = edges[i].y;
        AdjNode* srcNode = (AdjNode*)malloc(sizeof(AdjNode));
        AdjNode* destNode = (AdjNode*)malloc(sizeof(AdjNode));
        srcNode->k = src;
        destNode->k = dest;
        addDirectedEdges(graph, srcNode, destNode);
    }

    //printf(" \n Number of edges %d", getNumEdges(graph));
    testNeighbors(graph);
    testInNeighbors(graph);
    testOutNeighbors(graph);
    testHasEdge(graph);

    return graph;
}

Graph* testUnDirectedGraph() {
    Edge edges[] = { {0,4}, {1,2}, {3,1}, {4,2}, {2,0}, {0,5}, {3,5} };
    int n = sizeof(edges) / sizeof(edges[0]);
    Graph* graph = createGraph(n);

    for (int i = 0; i < n; i++) {
        int src = edges[i].x;
        int dest = edges[i].y;
        AdjNode* srcNode = (AdjNode*)malloc(sizeof(AdjNode));
        AdjNode* destNode = (AdjNode*)malloc(sizeof(AdjNode));
        srcNode->k = src;
        destNode->k = dest;
        addUndirectedEdges(graph, srcNode, destNode);
    }
    //printf(" \n Number of edges %d", getNumEdges(graph));
    testNeighbors(graph);
    testHasEdge(graph);

    return graph;
}
