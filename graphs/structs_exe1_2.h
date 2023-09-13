#define MAX 99

typedef struct Graph {
    int n;
    int* state[MAX][MAX];
    int** matrix;
}Graph;

typedef struct Edge {
    int x, y;
    int d;
    struct Edge* parent;
}Edge;

typedef struct AdjNode {
    int k;
    struct AdjNode* next;
    struct AdjNode* prev;

}AdjNode;

typedef struct AdjList {
    int size;
    struct AdjNode* head;
}AdjList;

typedef struct QueueNode {
    Edge* edge;
    struct QueueNode* next;
    struct QueueNode* prev;
}QueueNode;

typedef struct Queue {
    int size;
    struct QueueNode* head;
}Queue;
