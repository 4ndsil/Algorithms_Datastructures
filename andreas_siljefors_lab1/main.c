#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "stack.h"
#include "queue.h"
#include "list.h"

int main() {
	S* stack = stack = (S*)malloc(sizeof(S));
	Q* queue = (Q*)malloc(sizeof(Q));

	//creates empty stack 
	createStack(stack);

	//creates empty queue
	createQueue(queue);

	//inserts array into stack
	testStack(stack);

	//deletes element from stack
	testPop(stack);

	//inserts array into queue
	testEnqueue(queue);

	//deletes element from queue
	testDequeue(queue);

	int L1[] = { 3, 1, 5, 10, 8, 7 };
	int L2[] = { 5, 2, 9, 6, 1, 2 };
	int size1 = sizeof(L1) / sizeof(L1[0]);
	int size2 = sizeof(L2) / sizeof(L2[0]);

	L* list1 = (L*)malloc(sizeof(L));
	L* list2 = (L*)malloc(sizeof(L));

	//creates L1
	list1 = createlist(L1, size1);
	//creates L2
	list2 = createlist(L2, size2);


	//tests maximum of L1
	testMax(list1, 10);

	//tests maximum of L2
	testMax(list2, 9);

	//tests minimum of L1
	testMin(list1, 1);

	//tests minimum of L2
	testMin(list2, 1);

	//tests predecessor of L1
	testPre(list1, 5);

	//tests successor of L1
	testSucc(list1, 5);

	//tests predecessor of L2
	testPre(list2, 9);

	//tests successor of L2
	testSucc(list2, 9);

	//tests and finds predecessor in L2 of maximum in L1
	testPreMax(list1, list2);

	//tests and finds predecessor in L1 of maximum in L2
	testPreMax(list2, list1);

	//deletes a node
	testDelete(list1, 10);

	return 0;

}