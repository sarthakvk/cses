/* 
 * Problem: Distinct Numbers
 * Link: https://cses.fi/problemset/task/1621
 * Author: sarthak<kumar.v.sarthak@gmail.com> 
 */

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

int main() {
        int n, ans{0};
        scanf(" %d", &n);
        set<int> vals;
        for (int i = 0; i < n; i++) {
                int t;
                scanf(" %d", &t);
                vals.insert(t);
        }
        printf("%d\n", vals.size());
}