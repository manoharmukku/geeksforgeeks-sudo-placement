/*
Author: Manohar Mukku
Date: 05.08.2018
Desc: Absolute Difference of 1
Link: https://practice.geeksforgeeks.org/problems/absolute-difference-1/0/
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M 5

int is_absolute_diff_1(char* str) {
    int i;
    for (i = 1; str[i] != '\0'; i++) {
        if (abs(str[i] - str[i-1]) != 1)
            return 0;
    }

    return 1;
}

int main() {
    int t;
    scanf ("%d", &t);

    while (t--) {
        int n, k;
        scanf ("%d %d", &n, &k);

        char** arr = (char**)calloc(n, sizeof(char*));
        int i;
        for (i = 0; i < n; i++) {
            arr[i] = (char*)calloc(M, sizeof(char));
            scanf ("%s", arr[i]);
        }

        int flag = 1;
        for (i = 0; i < n; i++) {
            if (atoi(arr[i]) < k && is_absolute_diff_1(arr[i])) {
                printf("%s ", arr[i]);
                flag = 0;
            }
        }
        if (flag)
            printf("-1\n");
        else
            printf("\n");

        for (i = 0; i < n; i++)
            free(arr[i]);
        free(arr);
    }

    return 0;
}
