/*
* Problem: Apple Division
* Link: https://cses.fi/problemset/task/1623/
* Author: sarthak<kumar.v.sarthak@gmail.com>
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
        int n;
        scanf("%d", &n);
        vector<long long> w(n);
        bitset<20> s(0);
        for (int i = 0; i < n; i++)
                scanf("%lld", &w[i]);
        long long md, ws = accumulate(w.begin(), w.end(), decltype(w)::value_type(0));
        md = ws;
        for (int i = 0; i < 1 << n; i++) {
                long long sum{0};
                for (int j = 0; j < n; j++) {
                        assert(sum >= 0);
                        if (i & (1 << j))
                                sum += w[j];
                }
                md = abs(2 * sum - ws) < md ? abs(2 * sum - ws) : md;
        }
        printf("%lld\n", md);
}
