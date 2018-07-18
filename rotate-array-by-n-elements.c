/* 
Author: Manohar Mukku
Date: 17.07.2018
Desc: GeeksforGeeks - Arrays - Rotate Array by n elements
Link: https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0/
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int T;
    scanf ("%d", &T);

    while (T--){
        int n, d;
        scanf ("%d %d", &n, &d);

        int* arr = (int*)malloc(n * sizeof(int));
        
        int i;
        for (i = 0; i < n; i++) 
            scanf ("%d", &arr[i]);

        for (i = (d+n)%n; i < n && i != (d-1+n)%n; i = (i+1+n)%n)
            printf("%d ", arr[i]);
        printf("%d\n", arr[(d-1+n)%n]);

        free(arr);
    }

    return 0;
}
