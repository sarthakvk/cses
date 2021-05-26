/*
 * Title: Towers
 * Link: https://cses.fi/problemset/task/1073
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
        int n, ans{0};
        vi ar;
        multiset<int> t;
        cin >> n;
        forl(i, 0, n) {
                int t;
                cin >> t;
                ar.push_back(t);
        }

        forl(i, 0, n) {
                auto lb = t.upper_bound(ar[i]);
                if (lb == t.end()) {
                        t.insert(ar[i]);
                        ans++;
                } else {
                        t.erase(lb);
                        t.insert(ar[i]);
                }
        }
        cout << ans << "\n";
}
