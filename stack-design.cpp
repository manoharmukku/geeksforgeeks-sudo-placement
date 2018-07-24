/*
Author: Manohar Mukku
Date: 24.07.2018
Desc: GeeksforGeeks - SP[1.3] - Stack Design
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    scanf ("%d", &t);

    while (t--) {
        stack<int> s;

        int q;
        scanf ("%d", &q);

        while (q--) {
            int op, ele;
            scanf ("%d", &op);
            if (op == 1) {
                scanf("%d", &ele);
                s.push(ele);
            }
            else if (op == 2) {
                if (!s.empty())
                    s.pop();
            }
            else if (op == 3) {
                if (!s.empty())
                    printf("%d\n", s.top());
                else
                    printf("-1\n");
            }
        }
    }

    return 0;
}
