#include<stdio.h>
#include<stdlib.h>
#include "insertion_sort.h"
#include "merge_sort.h"

int testInsertionSortL1(int*L, int LSize) {

    printf("\nunsorted L1: ");
    printArr(L, LSize);

    insertionSort(L, LSize);

    printf("\nsorted L1: ");
    printArr(L, LSize);
    return 1;
}

int testInsertionSortL2(int* L, int LSize) {

    printf("\nunsorted L2: ");
    printArr(L, LSize);

    insertionSort(L, LSize);

    printf("\nsorted L2: ");
    printArr(L, LSize);
    return 1;

}

int testInsertionSortPnr(int* L, int LSize) {

    printf("\nunsorted Pnr: ");
    printArr(L, LSize);

    insertionSort(L, LSize);

    printf("\nsorted Pnr: ");
    printArr(L, LSize);
    return 1;
}
int testInsertionSortfile(int*L, int LSize) {

    printf("\nunsorted file: ");
    printArr(L, LSize);

    insertionSort(L, LSize);

    printf("\nsorted file: ");
    printArr(L, LSize);
    return 1;
}

int testMergeSortL1(int* L, int LSize) {

    printf("\nunmerged L1: ");
    printArr(L, LSize);

    mergeSort(L, 0,  LSize-1);
    printf("\nmerged L1: ");
    printArr(L, LSize);
    return 1;
}

int testMergeSortL2(int* L, int LSize) {

    printf("\nunmerged L2: ");
    printArr(L, LSize);

    mergeSort(L, 0, LSize-1);

    printf("\nmerged L2: ");
    printArr(L, LSize);
    return 1;
}

int testMergeSortPnr(int* L, int LSize) {

    printf("\nunmerged Pnr: ");
    printf("\nUnsorted array: ");
    printArr(L, LSize);

    mergeSort(L, 0, LSize - 1);

    printf("\nmerged Pnr: ");
    printf("\nSorted array : ");
    printArr(L, LSize);
    return 1;
}

int testMergeSortfile(int *L, int LSize) {

    printf("\nunmerged file: ");
    printf("\nUnsorted array: ");
    printArr(L, LSize);

    printf("\nmerged file: ");
    mergeSort(L, 0, LSize- 1);

    printf("\nSorted array: ");
    printArr(L, LSize);
    return 1;
}
