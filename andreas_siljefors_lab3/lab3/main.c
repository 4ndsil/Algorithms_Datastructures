#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "load_file.h"
#include "treeOperations.h"

int main(int argc, char* argv[]){

	node* root = NULL;


	//printf("\nLoad files sorting problem");
	
	//const char* fName = argv[1];
	//fName = "test-10-1-problem";
	//int* a = load_file(fName);

	//int size = a[0];

	/*root  = insert(root,a[0]);
	for (int i = 1; i < size; i++) {	
		int data = a[i];
		insert(root, data);
	}

	node* n = search(root,72);*/

	printf("\nDummy data tests");
	root = insert(root, 6);
	testinsert(root, 5);
	testinsert(root, 9);
	testinsert(root,2);
	testinsert(root, 7);

	//prints nodes in sorted order
	testTreeWalk(root);

	testdepth(root, 3);
	testsize(root, 5);

	testsearch(root, 2);
	testminimum(root, 2);
	testmaximum(root, 9);
	testdelete(root, 6);
	testsuccessor(root, 2);
	testpredecessor(root, 7);
	testdepth(root, 3);
	testsize(root, 4);

	
	
}