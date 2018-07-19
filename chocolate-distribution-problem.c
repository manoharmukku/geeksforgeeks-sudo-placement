/*
Author: Manohar Mukku
Date: 19.07.2018
Desc: GeeksforGeeks - Arrays - Chocolate Distribution Problem
Link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0/
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

        int i;
        for (i = 0; i < n; i++)
            scanf ("%d", &arr[i]);

        qsort(arr, n, sizeof(int), cmpfunc);

        int m;
        scanf ("%d", &m);

        int min_diff = INT_MAX;
        for (i = 0; i <= n-m; i++) {
            if (arr[i+m-1] - arr[i] < min_diff)
                min_diff = arr[i+m-1] - arr[i];
        }

        printf("%d\n", min_diff);

        free(arr);
    }

    return 0;
}
