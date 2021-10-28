#include <stdio.h>
#include <stdlib.h>
#include "structs_exe3.h"
#include "exe3.h"

void testExe3() {

    Graph_scc* graph = initializeGraph();
    DFS(graph);
    Graph_scc* transpose = transposeGraph(graph);
    int scc = DFS_transpose(transpose);
    printf("****");
    //printMatrix_exe3(transpose);
    printf("\n Number of strongly connected components is: %d", scc);

    free(graph);
    free(transpose);
}

Graph_scc* initializeGraph() {

    int n = 11;

    Graph_scc* graph = createGraph_exe3(n);

    addEdge(graph, 1, 0);
    addEdge(graph, 0, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 6);
    addEdge(graph, 6, 4);
    addEdge(graph, 4, 3);
    addEdge(graph, 7, 6);
    addEdge(graph, 7, 8);
    addEdge(graph, 8, 5);
    addEdge(graph, 5, 7);
    addEdge(graph, 8, 9);
    addEdge(graph, 9, 10);
    addEdge(graph, 10, 9);

    return graph;
}