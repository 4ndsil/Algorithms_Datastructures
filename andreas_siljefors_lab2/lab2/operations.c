#include<stdio.h>
#include<stdlib.h>
#include "limits.h"
#include "insertion_sort.h"
#include "merge_sort.h"

void insertionSort(int* arr, int n) {
    int i, k, j;

    for (j = 0; j < n; j++) {
        k = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > k) {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = k;
    }
}

void merge(int*arr, int p, int q, int r) {
    int i, j, k;
    int n1 = (q - p + 1);
    int n2 = (r - q);
    int* L= malloc(n1*sizeof(int));
    int* R = malloc(n2 * sizeof(int));

    L[n1];
    R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = (int)malloc(sizeof(int));
        L[i] = arr[p + i];
    }
    for (j = 0; j <n2; j++) {
        R[j] = (int)malloc(sizeof(int));
        R[j] = arr[q + 1 + j];
    }

    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j< n2) {
        
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;

    }while (i < n1)
    {
        arr[k] = L[i++];
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j++];
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int* arr, int p, int n) {
    if (p < n) {
        int q = p + (n - p) / 2;

        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, n);
        merge(arr, p, q, n);
    }
}
void printArr(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}