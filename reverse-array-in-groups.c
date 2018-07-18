/*
Author: Manohar Mukku
Date: 18.07.2018
Desc: GeeksforGeeks - Sudo Placement - Arrays - Reverse array in groups
LinK: https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0/
*/

#include <stdio.h>
#include <stdlib.h>

#define min(x, y) (x < y ? x : y)

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

        int k;
        scanf ("%d", &k);

        int m = k-1;
        while (1) {
            for (i = min(m, n-1); i > m-k; i--)
                printf("%d ", arr[i]);
            m += k;
            if (m >= n+k)
                break;
        }
        printf("\n");

        free(arr);
    }
    return 0;
}
