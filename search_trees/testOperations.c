#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "treeOperations.h"

int testinsert(node* root, int data){
	if (root) {
		insert(root, data);
		printf("\nnew node %d inserted", data);
		return 1;
	}
	else {
		printf("insertion failed");
		return 0;
	}
}

int testsearch(node* root, int data){

		node* returned = search(root,data);
	if (data == returned->data) {
		printf("\nsuccess");
		printf("\nsearched node: %d, returned node: %d", data, returned->data);
		return 1;
	}
	else {
		printf("\nfail");
		printf("\nsearched node: %d, returned node: %d", data, returned->data);
		return 0;
	}
}

int testminimum(node* root, int data){
	node* returned = minimum(root);
	if (data == returned->data) {
		printf("\nsuccess");
		printf("\nexpected min value: %d, returned value: %d", data, returned->data);
		return 1;
	}
	else {
		printf("\nfail");
		printf("\nexpected min value: %d, returned value: %d", data, returned->data);
		return 0;
	}
}

int testmaximum(node* root,int data){
	node* returned = maximum(root);
	if (data == returned->data) {
		printf("\nsuccess");
		printf("\nexpected max value: %d, returned value: %d", data, returned->data);
		return 1;
	}
	else {
		printf("\nfail");
		printf("\nexpected max value: %d, returned value: %d", data, returned->data);
		return 0;
	}
}

int testdelete(node* root, int data){
	node* returned = delete(root,data);
	if (returned->data < data) {
		printf("\nsuccess");
		printf("\nreturned value: %d. %d removed", returned->data, data);
		return 1;
	}
	else if (returned->data > data){
		printf("\nsuccess");
		printf("\nreturned value: %d. %d removed,",returned->data, data);
		return 1;
	}
	else {
		printf("\ntest failed");
		return 0;
	}
}

int testsuccessor(node* n, int data){
	node* expected = malloc(sizeof(node));
	expected = search(n, data);
	node* returned = successor(expected);
	if (returned != NULL) {
		if (expected->data < returned->data) {
			printf("\nsuccess");
			printf("\nsuccessor of %d: returned successor value: %d", expected->data, returned->data);
			return 1;
		}
		else {
			printf("\nfail");
			printf("\nsuccessor of: %d: returned successor value: %d", expected->data, returned->data);
			return 0;
		}
	}
	else {
		printf("\nfail");
		printf("\nsuccessor of node %d not found", returned->data);
		return 0;
	}
}

int testpredecessor(node*n,int data){
	node* expected = malloc(sizeof(node));
	expected = search(n, data);
	node* returned = predecessor(expected);
	if (returned != NULL) {
		if (expected->data > returned->data) {
			printf("\nsuccess");
			printf("\npredecessor of %d: returned predecessor node: %d", expected->data, returned->data);
			return 1;
		}
		else {
			printf("\nfail");
			printf("\npredecessor of %d: returned predecessor node: %d", expected->data, returned->data);
			return 0;
		}
	}
	else {
		printf("\nfail");
		printf("\npredecessor of node %d not found",returned->data);
		return 0;
	}
}

int testdepth(node* root, int value){
	int y = treedepth(root);
	if(y == value) {
		printf("\nsuccess");
		printf("\nexpected depth: %d, returned depth: %d", value, y);
		return 1;
	}
	else {
		printf("\nfail");
		printf("\nexpected depth: %d, returned depth: %d", value, y);
		return 0;
	}	
}

int testsize(node*root, int nodes) {
	 int x = treesize(root);
	 if (x == nodes) {
		 printf("\nsuccess");
		 printf("\nexpected size: %d, returned size: %d", nodes, x);
		 return 1;
	 }
	 else {
		 printf("\nfail");
		 printf("\nexpected size: %d, returned size: %d", nodes, x);
		 return 0;
	 }
}

void testTreeWalk(node*root) {
	inorderwalk(root);
}