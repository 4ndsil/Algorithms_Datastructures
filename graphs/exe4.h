
//operations
int Bellman_Ford(Graph_sssp* graph, int u);
Graph_sssp* createGraph_exe4(int n);
void initialize_Single_Source(Graph_sssp* graph, int u);
void relax(Graph_sssp* graph, int src, int dest, int w);
int getDistance(int i);
//tests

void testExe4_1();
void testExe4_2();

