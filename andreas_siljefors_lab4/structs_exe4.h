#pragma once
#define MAX 99

typedef struct Graph_sssp {
	int n;
	int* parent[MAX];
	int** matrix;
}Graph_sssp;

