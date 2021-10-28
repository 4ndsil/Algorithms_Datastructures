#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"
#include "merge_sort.h"
#include "load_file.h"

int main(int argc, char* argv[])
{

	int L1[] = { 3, 1, 5, 10, 8, 7 };
	int L2[] = { 5, 2, 9, 6, 1, 2 };
	int L3[] = { 9, 6, 0, 9, 0, 7 };
	int L1Size = sizeof(L1) / sizeof(L1[0]);
	int L2Size = sizeof(L2) / sizeof(L2[0]);
	int L3Size = sizeof(L3) / sizeof(L3[0]);

	int* list1 = L1;
	int* list2 = L2;
	int* list3 = L3;

	const char* fName = argv[1];
	fName = "test-100-5-problem";
	int* a = load_file(fName);

	int size = a[0];

	//insertion sort of L1
	//testInsertionSortL1(list1, L1Size);
	//insertion sort of L2
	//testInsertionSortL2(list2, L2Size);
	//insertion sort of pnr
	//testInsertionSortPnr(list3, L3Size);
	//insertion sort of file
	//testInsertionSortfile(a, size);

	//merge sort of L1
	testMergeSortL1(list1, L1Size);
	//merge sort of L2
	testMergeSortL2(list2, L2Size);
	//merge sort of pnr
	testMergeSortPnr(list3, L3Size);
	//merge sort of file
	testMergeSortfile(a, size);
}