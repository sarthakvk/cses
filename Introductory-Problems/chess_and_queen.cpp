/*
 * Problem: Chessboard and Queens
 * Link: https://cses.fi/problemset/task/1624
 * Author: sarthak<kumar.v.sarthak@gmail.com>
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 8;
int ans{0};
vector<int> r(8, 0), c(8, 0), dig1(2 * N - 1, 0), dig2(2 * N - 1, 0);
unordered_map<int, vector<int>> b;

bool blocked(int x, int y) {
        for (int& i : b[x]) {
                if (i == y)
                        return true;
        }
        return false;
}

bool isval(int x, int y) {
        if (r[x] == 0 && c[y] == 0 && dig1[x + y] == 0 && dig2[N + x - y - 1] == 0)
                return true;
        return false;
}

void ins(int x, int y, int i) {
        r[x] = i;
        c[y] = i;
        dig1[x + y] = i;
        dig2[N + x - y - 1] = i;
}

void solve(int x) {
        if (x == N) {
                ans++;
                return;
        }

        for (int i = 0; i < N; i++) {
                if (isval(x, i) && !blocked(x, i)) {
                        ins(x, i, 1);
                        solve(x + 1);
                        ins(x, i, 0);
                }
        }
}

int main() {
        for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                        char t;
                        scanf(" %c", &t);
                        if (t == '*') {
                                b[i].push_back(j);
                        }
                }
        }

        solve(0);
        cout << ans << "\n";
}