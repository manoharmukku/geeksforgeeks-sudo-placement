/*
Author: Manohar Mukku
Date: 17.07.2018
Desc: GeeksforGeeks - Sudo Placement [1.2] - Beautiful pairs
*/

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

int main() {
    int T;
    scanf ("%d", &T);

    while (T--) {
        int n1;
        scanf ("%d", &n1);

        int* arr1 = (int*)malloc(n1 * sizeof (int));

        int i;
        for (i = 0; i < n1; i++) 
            scanf ("%d", &arr1[i]);

        int n2;
        scanf ("%d", &n2);

        int* arr2 = (int*)malloc(n2 * sizeof(int));

        for (i = 0; i < n2; i++)
            scanf ("%d", &arr2[i]);

        qsort(arr1, n1, sizeof(int), cmpfunc);

        int j, k;
        for (i = 0; i < n2; i++) {
            j = 0, k = n1 - 1;
            while (j < k) {
                if (arr1[j] + arr1[k] == arr2[i])
                    break;
                else if (arr1[j] + arr1[k] < arr2[i])
                    j++;
                else
                    k--;
            }
            if (j < k)
                break;
        }

        if (i < n2)
            printf("1\n");
        else
            printf("0\n");

        free(arr1);
        free(arr2);
    }
    return 0;
}
