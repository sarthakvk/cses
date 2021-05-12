/*
 * Problem: Ferris Wheel
 * Link: https://cses.fi/problemset/task/1090
 * Author: sarthak<sarthakchaudahry13@gmail.com>
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
        int n, x, g{0};
        vector<int> w;
        stack<int> q;
        scanf("%d%d", &n, &x);
        for (int i = 0; i < n; i++) {
                int t;
                scanf("%d", &t);
                w.push_back(t);
        }

        sort(w.begin(), w.end());

        for (int i = n - 1; i >= 0; i--) {
                if (w[i] == x)
                        g++;
                else if (!q.empty()) {
                        int t = q.top();
                        if (w[i] + t <= x) {
                                g++;
                                q.pop();
                        } else
                                q.push(w[i]);
                } else
                        q.push(w[i]);
        }
        printf("%d\n", g + (int)q.size());
}
