/*
Author: Manohar Mukku
Date: 05.08.2018
Desc: Subarray with given sum
Link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0/
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf ("%d", &t);

    while (t--) {
        int n, s;
        scanf ("%d %d", &n, &s);

        int* arr = (int*)malloc(n * sizeof(int));

        int i;
        for (i = 0; i < n; i++)
            scanf ("%d", &arr[i]);

        int j;
        int flag = 0;
        for (i = 0; i < n; i++) {
            int sum = 0;
            for (j = i; j < n; j++) {
                sum += arr[j];
                if (sum == s) {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }

        if (flag)
            printf("%d %d\n", i+1, j+1);
        else
            printf("-1\n");

        free(arr);
    }
    return 0;
}
