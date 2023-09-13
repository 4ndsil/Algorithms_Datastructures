#define MAX 99

typedef struct Graph_scc {
	int n;
	int* timeD[MAX];
	int* timeF[MAX];
	int* color[MAX];
	int** matrix;
}Graph_scc;

typedef struct SccNode {
	int k;
	struct SccNode* next;
	struct SccNode* prev;

}SccNode;

typedef struct SccList {
	struct SccNode* head;
	int n;
}SccList;
