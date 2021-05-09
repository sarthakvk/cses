/*
 * Problem: Digit Queries
 * Link: https://cses.fi/problemset/task/2431
 * Author: sarthak<kumar.v.sarthak@gmail.com>
 */

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull nth(int n) {
        if (n < 1)
                return 0;
        else if (n == 1)
                return 9;
        else
                return n * 9 * (ull)pow(10, n - 1) + nth(n - 1);
}

int ans;

int fdig(ull dig, int n) {
        if (dig == 0) {
                return 0;
        }
        int k = 1 + fdig(dig / 10, n);
        if (k == n) {
                ans = dig % 10;
        }
        return k;
}

int bs(ull k) {
        int d = 0;
        for (int i = 18; i >= 1; i /= 2) {
                while (k > nth(i + d)) {
                        d += i;
                }
        }
        return ++d;
}

int main() {
        int q;
        scanf(" %d", &q);
        while (q--) {
                ull k;
                scanf(" %llu", &k);
                int d = bs(k);
                ull kth = k - nth(d - 1);
                ull dig = (ull)pow(10, d - 1) + (ull)ceil(kth / (double)d) - 1;
                int dth = kth % d;
                
                if (dth == 0)
                        ans = dig % 10;
                else
                        fdig(dig, dth);
                printf("%d\n", ans);
        }
}