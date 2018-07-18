/* 
Author: Manohar Mukku
Date: 17.07.2018
Desc: GeeksforGeeks - Arrays - Leaders in an array
Link: https://practice.geeksforgeeks.org/problems/reverse-an-array/0/
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
            scanf("%d", &arr[i]);

        for (i = n-1; i >= 0; i--) 
            printf("%d ", arr[i]);
        printf("\n");

        free(arr);
    }

    return 0;
}
