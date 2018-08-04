/*
Author: Manohar Mukku
Date: 04.08.2018
Desc: Maximum of all subarrays of size k
Link: https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0/
Acks: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
*/

#include <iostream>
#include <stdlib.h>
#include <deque>
using namespace std;

int main() {
    int t;
    scanf ("%d", &t);

    while (t--) {
        int n, k;
        scanf ("%d %d", &n, &k);

        int* arr = (int*)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            scanf ("%d", &arr[i]);

        deque<int> Q;

        for (int i = 0; i < k; i++) {
            while (!Q.empty() && arr[Q.back()] <= arr[i])
                Q.pop_back();

            Q.push_back(i);
        }

        for (int i = k; i < n; i++) {
            printf("%d ", arr[Q.front()]);

            while (!Q.empty() && Q.front() <= i-k)
                Q.pop_front();

            while (!Q.empty() && arr[Q.back()] < arr[i])
                Q.pop_back();

            Q.push_back(i);
        }
        printf("%d\n", arr[Q.front()]);

        free(arr);
    }

    return 0;
}
