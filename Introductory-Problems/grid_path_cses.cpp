/*
 * Problem: Grid Paths
 * Link: https://cses.fi/problemset/task/1625
 * Author: sarthak<kumar.v.sarthak@gmail.com>
 */
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <chrono>

using namespace std;

enum Move {
        U,
        D,
        L,
        R,
        nil,
};

const int n = 7;
int grid[n][n], ans{0}, cnt{0};
char p[48];

inline void createGrid() {
        for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                        grid[i][j] = 0;
}

inline bool isValid(int i, int j) {
        if (i < n && i >= 0 && j < n && j >= 0 && grid[i][j] == 0)
                return true;
        return false;
}

inline bool pathExist(int i, int j, Move mv) {
        bool U = (mv == Move::U && !isValid(i - 1, j) && isValid(i, j + 1) && isValid(i, j - 1));
        bool D = (mv == Move::D && !isValid(i + 1, j) && isValid(i, j + 1) && isValid(i, j - 1));
        bool L = (mv == Move::L && !isValid(i, j - 1) && isValid(i + 1, j) && isValid(i - 1, j));
        bool R = (mv == Move::R && !isValid(i, j + 1) && isValid(i + 1, j) && isValid(i - 1, j));

        if (U || D || L || R)
                return false;
        return true;
}

inline Move toenum(char a) {
        Move rtn;
        switch (a) {
                case 'U':
                        rtn = Move::U;
                        break;
                case 'D':
                        rtn = Move::D;
                        break;
                case 'L':
                        rtn = Move::L;
                        break;
                case 'R':
                        rtn = Move::R;
                        break;
                default:
                        break;
        }
        return rtn;
}

void solve(int i, int j, int c, Move m) {
        cnt++;
        if (i == n - 1 && j == 0) {
                if (cnt == n * n)
                        ans++;
                cnt--;
                return;
        }
        if (m == Move::nil || pathExist(i, j, m)) {
                grid[i][j] = 1;
                if (p[c] == '?') {
                        if (isValid(i + 1, j))
                                solve(i + 1, j, c + 1, Move::D);
                        if (isValid(i - 1, j))
                                solve(i - 1, j, c + 1, Move::U);
                        if (isValid(i, j + 1))
                                solve(i, j + 1, c + 1, Move::R);
                        if (isValid(i, j - 1))
                                solve(i, j - 1, c + 1, Move::L);
                } else {
                        Move mv = toenum(p[c]);
                        if (mv == Move::U && isValid(i - 1, j))
                                solve(i - 1, j, c + 1, mv);
                        else if (mv == Move::D && isValid(i + 1, j))
                                solve(i + 1, j, c + 1, mv);
                        else if (mv == Move::L && isValid(i, j - 1))
                                solve(i, j - 1, c + 1, mv);
                        else if (mv == Move::R && isValid(i, j + 1))
                                solve(i, j + 1, c + 1, mv);
                }
                grid[i][j] = 0;
        }
        cnt--;
}

int main() {
        scanf(" %s", p);
        auto s = chrono::high_resolution_clock::now();
        createGrid();
        solve(0, 0, 0, Move::nil);
        printf("%d\n", ans);
        auto e = chrono::high_resolution_clock::now();
        auto d = chrono::duration_cast<chrono::milliseconds>(e-s).count();
        printf("Execution Time: %d\n",d);
}