/*
Author: Manohar Mukku
Date: 19.07.2018
Desc: GeeksforGeeks - Arrays - Sort in specific order
Link: https://practice.geeksforgeeks.org/problems/sort-in-specific-order/0/
*/

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int t;
    scanf ("%d", &t);

    while (t--) {
        int n;
        scanf ("%d", &n);

        int* arr = (int*)malloc(n * sizeof(int));
        int* output = (int*)malloc(n * sizeof(int));

        int i;
        for (i = 0; i < n; i++)
            scanf ("%d", &arr[i]);

        qsort(arr, n, sizeof(int), cmpfunc);

        int odd_count = 0;
        for (i = 0; i < n; i++)
            if (arr[i] & 1)
                ++odd_count;

        int odd_index = odd_count - 1;
        int even_index = odd_count;

        for (i = 0; i < n; i++) {
            if (arr[i] & 1) {
                output[odd_index] = arr[i];
                --odd_index;
            }
            else {
                output[even_index] = arr[i];
                ++even_index;
            }
        }

        for (i = 0; i < n; i++)
            printf("%d ", output[i]);
        printf("\n");

        free(arr);
        free(output);
    }

    return 0;
}
