/* 
Author: Manohar Mukku
Date: 17.07.2018
Desc: GeeksforGeeks - Arrays - Leaders in an array
Link: https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0/
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf ("%d", &T);

    while (T--) {
        int n;
        scanf ("%d", &n);

        int* arr = (int*)malloc(n * sizeof(int));

        int i;
        for (i = 0; i < n; i++)
            scanf ("%d", &arr[i]);

        int* leaders = (int*)malloc(n * sizeof(int));

        leaders[0] = arr[n-1];

        int max = leaders[0];
        for (i = 1; i < n; i++) {
            if (arr[n-i-1] > max) {
                leaders[i] = arr[n-i-1];
                max = arr[n-i-1];
            }
            else
                leaders[i] = -1;
        }

        for (i = n-1; i >= 0; i--) {
            if (leaders[i] != -1)
                printf("%d ", leaders[i]);
        }
        printf("\n");

        free(arr);
        free(leaders);
    }

    return 0;
}
