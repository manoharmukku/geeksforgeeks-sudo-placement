/*
Author: Manohar Mukku
Date: 05.08.2018
Desc: Type of array
Link: https://practice.geeksforgeeks.org/problems/type-of-array/0/
*/

#include <stdio.h>
#include <stdlib.h>

#define ASC 1
#define DESC 2
#define DESC_ROT 3
#define ASC_ROT 4

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

        int pattern = 0;
        int max = arr[0];
        for (i = 1; i < n; i++) {
            if (arr[i] > arr[i-1])
                ++pattern;
            else
                --pattern;
            if (arr[i] > max)
                max = arr[i];
        }

        if (pattern == n-1)
            printf("%d %d\n", max, ASC);
        else if (pattern == 1-n)
            printf("%d %d\n", max, DESC);
        else if (pattern < 0)
            printf("%d %d\n", max, DESC_ROT);
        else if (pattern > 0)
            printf("%d %d\n", max, ASC_ROT);
        
        free(arr);
    }

    return 0;
}
