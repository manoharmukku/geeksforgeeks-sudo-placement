/*
Author: Manohar Mukku
Date: 19.07.2018
Desc: GeeksforGeeks - Arrays - Count distinct elements in every window
Link: https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1/
*/

#include <stdio.h>
#include <stdlib.h>

#define M 100

int getDistinctCount(int* counts) {
    int i, count = 0;
    for (i = 0; i < M; i++)
        if (counts[i])
            ++count;
    return count;
}

int main() {
    int t;
    scanf ("%d", &t);

    while (t--) {
        int n, k;
        scanf ("%d %d", &n, &k);

        int* arr = (int*)malloc(n * sizeof(int));

        int i;
        for (i = 0; i < n; i++)
            scanf ("%d", &arr[i]);

        int* counts = (int*)calloc(M, sizeof(int));

        for (i = 0; i < k; i++)
            ++counts[arr[i]-1];
        
        printf("%d ", getDistinctCount(counts));

        for (i = 1; i <= n-k; i++) {
            --counts[arr[i-1]-1];
            ++counts[arr[i+k-1]-1];
            printf("%d ", getDistinctCount(counts));
        }
        printf("\n");

        free(arr);
        free(counts);
    }

    return 0;
}
