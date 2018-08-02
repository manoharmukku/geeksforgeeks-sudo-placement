/*
Author: Manohar Mukku
Date: 01.08.2018
Desc: GeeksforGeeks - Arrays - Find the fine
Link: https://practice.geeksforgeeks.org/problems/find-the-fine/0/
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf ("%d", &t);

    while (t--) {
        int n, given_date;
        scanf ("%d %d", &n, &given_date);

        int i;
        int* car_no = (int*)calloc(n, sizeof(int));
        int* penalty = (int*)calloc(n, sizeof(int));

        for (i = 0; i < n; i++)
            scanf ("%d", &car_no[i]);
        for (i = 0; i < n; i++)
            scanf ("%d", &penalty[i]);

        int total_penalty = 0;
        for (i = 0; i < n; i++)
            if ((given_date ^ car_no[i]) & 1)
                total_penalty += penalty[i];

        printf("%d\n", total_penalty);

        free(car_no);
        free(penalty);
    }

    return 0;
}