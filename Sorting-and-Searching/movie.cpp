/*
 * Title: Movie Festival
 * Link: https://cses.fi/problemset/task/1629
 * Author: sarthak<kumar.v.sarthak@gmail.com>
 */

#include <bits/stdc++.h>

using namespace std;

struct movie {
        int s;
        int e;
};

bool cmp(movie& a, movie& b) {
        return a.e < b.e;
}

int main() {
        int n, ans{0};
        scanf("%d", &n);
        vector<movie> m;
        for (int i = 0; i < n; i++) {
                int s, e;
                scanf("%d%d", &s, &e);
                m.push_back(movie{s, e});
        }
        sort(m.begin(), m.end(), cmp);

        int prev{0};
        for (movie& i : m) {
                if (i.s >= prev) {
                        ans++;
                        prev = i.e;
                };
        }
        printf("%d\n",ans);
}