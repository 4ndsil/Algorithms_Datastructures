#include <stdio.h>
#include <stdlib.h>
#include "structs_exe1_2.h"
#include "structs_exe3.h"
#include "structs_exe4.h"
#include "exe1.h"
#include "exe2.h"
#include "exe3.h"
#include "exe4.h"

int main() {

	printf("\n ******Exercise 1******");

	//Tests for both directed and undirected graphs

	printf("\n\n Exe1: directed graph");
	testDirectedGraph();

	printf("\n Exe1: undirected graph");
	testUnDirectedGraph();

	printf("\n ******Exercise 2******");

	testExe2();

	printf("\n ******Exercise 3******");

	testExe3();

	printf("\n ******Exercise 4******");

	printf("\n Exe4: graph 1");
	testExe4_1();

	/*printf("\n\n Exe4: graph 2");
	testExe4_2();*/

	return 0;
}