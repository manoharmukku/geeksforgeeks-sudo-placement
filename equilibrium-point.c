/*
Author: Manohar Mukku
Date: 04.08.2018
Desc: Equilibrium Point
Link: https://practice.geeksforgeeks.org/problems/equilibrium-point/0/
*/

#include <stdio.h>
#include <stdlib.h>

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

        int sum = 0;
        for (i = 0; i < n; i++) 
            sum += arr[i];

        int sum_before = 0;
        int sum_after;
        for (i = 0; i < n; i++) {
            sum_after = sum - sum_before - arr[i];
            if (sum_before == sum_after) {
                printf("%d\n", i+1);
                break;
            }
            sum_before += arr[i];
        }

        if (i == n)
            printf("-1\n");

        free(arr);
    }
    return 0;
}
