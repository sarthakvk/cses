/*
 * Problem: Apartments
 * Link: https://cses.fi/problemset/task/1084
 * Author: sarthak<kumar.v.sarthak@gmail.com>
 */

#pragma GCC optimze("Ofast")

#include <bits/stdc++.h>

using namespace std;

bool valid(int& x, int& y, int& k) {
        if (y == 0) return false;
        if (y >= x - k && y <= x + k)
                return true;
        return false;
}

int main() {
        int n, m, k, ans{0};
        scanf("%d%d%d", &n, &m, &k);

        vector<int> vn, vm;
        for (int i = 0; i < n; i++) {
                int tmp;
                scanf(" %d", &tmp);
                vn.push_back(tmp);
        }
        for (int i = 0; i < m; i++) {
                int tmp;
                scanf(" %d", &tmp);
                vm.push_back(tmp);
        }
        sort(vn.begin(), vn.end());
        sort(vm.begin(), vm.end());
        auto s = chrono::high_resolution_clock::now();
        for (int& j : vn) {
                int i = lower_bound(vm.begin(), vm.end(), j) - vm.begin();
                if (i == m) i -= 1;
                i = valid(j, vm[i], k) ? i : i - 1;
                if (i == 0 && valid(j, vm[i], k)) {
                        vm[i] = 0;
                        ans++;
                } else if (i < m && i > 0 && valid(j, vm[i], k)) {
                        int idx = -1;
                        while(valid(j, vm[i], k)) i--;
                        idx++;
                        vm[idx] = 0;
                        ans++;
                }
        }
        printf("%d\n", ans);
        auto e = chrono::high_resolution_clock::now();
        cout << chrono::duration_cast<chrono::microseconds>(e-s).count();

}