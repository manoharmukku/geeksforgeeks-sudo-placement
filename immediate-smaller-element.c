/* 
Author: Manohar Mukku
Date: 17.07.2018
Desc: GeeksforGeeks - Arrays - Immediate Smaller Element
Link: https://practice.geeksforgeeks.org/problems/immediate-smaller-element/0/
*/

#include <stdio.h>

int main() {
    int T;
    scanf ("%d", &T);

    while (T--) {
        int n;
        scanf ("%d", &n);

        int prev, curr;
        scanf ("%d", &prev);

        while (--n){
            scanf ("%d", &curr);
            if (curr < prev)
                printf("%d ", curr);
            else
                printf("-1 ");
            prev = curr;
        }
        printf("-1\n");
    }

    return 0;
}
