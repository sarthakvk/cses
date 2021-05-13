/*
 * Problem: Concert Tickets
 * Link: https://cses.fi/problemset/task/1091
 * Author sarthak<kumar.v.sarthak@gmail.com>
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
        int n, m;
        scanf("%d%d", &n, &m);

        multiset<int> t;
        vector<int> c;

        for (int i = 0; i < n; i++) {
                int a;
                scanf("%d", &a);
                t.insert(a);
        }

        for (int i = 0; i < m; i++) {
                int a;
                scanf("%d", &a);
                c.push_back(a);
        }
        for (int& i : c) {
                int out{-1};
                auto tic = t.upper_bound(i);
                if (tic != t.begin()) {
                        out = *(--tic);
                        t.erase(tic);
                }
                printf("%d\n", out);
        }
}