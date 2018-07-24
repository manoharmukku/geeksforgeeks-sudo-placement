/*
Author: Manohar Mukku
Date: 24.07.2018
Desc: GeeksforGeeks - SP[1.3] - Playing with Stacks
*/

#include <iostream>
#include <stack>
using namespace std;

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

        stack<int> a;
        stack<int> b;
        stack<int> c;

        for (i = n-1; i >= 0; i--)
            a.push(arr[i]);

        int count = 0;
        int curr = 1;
        while (1) {
            if (!a.empty()) {
                if (a.top() == curr) {
                    a.pop();
                    c.push(curr);
                    ++count;
                    ++curr;
                }
                else if (!b.empty() && b.top() == curr) {
                    b.pop();
                    c.push(curr);
                    ++count;
                    ++curr;
                }
                else {
                    int x = a.top();
                    a.pop();
                    b.push(x);
                    ++count;
                }
            }
            else {
                while (!b.empty() && b.top() == curr) {
                    int x = b.top();
                    b.pop();
                    c.push(x);
                    ++count;
                    ++curr;
                }
                break;
            }
        }

        if (b.empty())
            printf("YES %d\n", count);
        else {
            printf("NO\n");
        }

        free(arr);
    }

    return 0;
}
