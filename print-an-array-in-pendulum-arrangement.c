/*
Author: Manohar Mukku
Date: 19.07.2018
Desc: GeeksforGeeks - Arrays - Print an array in Pendulum Arrangement
Link: https://practice.geeksforgeeks.org/problems/print-an-array-in-pendulum-arrangement/0/
*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int cmpfunc(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int T;
    scanf ("%d", &T);

    while (T--) {
        int n;
        scanf ("%d", &n);

        int* arr = (int*)malloc(n * sizeof(int));
        int* output = (int*)malloc(n * sizeof(int));

        int i;
        for (i = 0; i < n; i++)
            scanf ("%d", &arr[i]);

        qsort(arr, n, sizeof(int), cmpfunc);

        int pos;
        if (n & 1)
            pos = n/2;
        else
            pos = (n-1)/2;

        int counter = 0;
        int isRight = TRUE;

        for (i = 0; i < n; i++) {
            output[pos] = arr[i];

            ++counter;
            
            if (isRight) {
                pos += counter;
                isRight = FALSE;
            }
            else {
                pos -= counter;
                isRight = TRUE;
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
