/*
Author: Manohar Mukku
Date: 04.08.2018
Desc: Pythagorean Triplet
Link: https://practice.geeksforgeeks.org/problems/pythagorean-triplet/0/
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

        int i;
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        qsort(arr, n, sizeof(int), cmpfunc);

        int j, k;
        int flag = 0;
        for (i = 2; i < n; i++) {
            j = 0, k = i-1;
            while (j < k) {
                if (arr[j] * arr[j] + arr[k] * arr[k] == arr[i] * arr[i]) {
                    flag = 1;
                    break;
                }
                else if (arr[j] * arr[j] + arr[k] * arr[k] < arr[i] * arr[i])
                    j++;
                else
                    k--;
            }
            if (flag)
                break;
        }

        if (flag)
            printf("Yes\n");
        else
            printf("No\n");

        free(arr);
    }
    return 0;
}
