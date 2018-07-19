/*
Author: Manohar Mukku
Date: 19.07.2018
Desc: GeeksforGeeks - Arrays - Find the closest number
Link: https://practice.geeksforgeeks.org/problems/find-the-closest-number/0/
*/

#include <stdio.h>

int main() {
    int t;
    scanf ("%d", &t);

    while (t--) {
        int n, k;
        scanf ("%d %d", &n, &k);

        int i, prev = -1000000, curr, result, flag = 0;
        for (i = 0; i < n; i++) {
            scanf ("%d", &curr);

            if (flag)
                continue;

            if (curr < k) {
                prev = curr;
            }
            else {
                if (curr - k <= k - prev)
                    result = curr;
                else
                    result = prev;

                flag = 1;
            }
        }

        if (flag == 0)
            result = curr;

        printf("%d\n", result);
    }

    return 0;
}
