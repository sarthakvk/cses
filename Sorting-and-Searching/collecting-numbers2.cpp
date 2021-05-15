/*
 * Title: Collecting Numbers 2
 * Link: https://cses.fi/problemset/task/2217
 * Author: sarthak<kumar.v.sarthak@gmail.com>
 */

#include <bits/stdc++.h>
#define forl(i, a, n) for (auto i = a; i < n; i++)
#define fore(i, a, n) for (auto i = a; i <= n; i++)
#define forg(i, a, n) for (auto i = a; i > n; i--)
#define fastio                            \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
        fastio;
        int n, m, ans{0};
        cin >> n >> m;
        vi ar;
        unordered_set<int> c;
        unordered_map<int, int> idx;
        forl(i, 0, n) {
                int t;
                cin >> t;
                ar.push_back(t);
        }

        forl(i, 0, n) {
                idx[ar[i]] = i;
                if (ar[i] == 1 || c.count(ar[i] - 1) == 0) ans++;
                c.insert(ar[i]);
        }

        while (m--) {
                int i, j, tmp;
                cin >> i >> j;
                tmp = i;
                i = min(i, j);
                j = max(tmp, j);
                i--, j--;
                if (idx.count(ar[i] + 1) && (idx[ar[i] + 1] > i && idx[ar[i] + 1] < j)) {
                        ans++;
                }
                if (idx.count(ar[i] - 1) && idx[ar[i] - 1] > i && idx[ar[i] - 1] < j) {
                        ans--;
                }

                if (idx.count(ar[j] + 1) && idx[ar[j] + 1] < j && idx[ar[j] + 1] > i) {
                        ans--;
                }
                if (idx.count(ar[j] - 1) && idx[ar[j] - 1] < j && idx[ar[j] - 1] > i) {
                        ans++;
                }

                if (idx.count(ar[j] + 1) && idx[ar[j] + 1] == i) {
                        ans--;
                }
                if (idx.count(ar[i] + 1) && idx[ar[i] + 1] == j) {
                        ans++;
                }
                idx[ar[i]] = j;
                idx[ar[j]] = i;
                swap(ar[i], ar[j]);
                cout << ans << "\n";
        }
}