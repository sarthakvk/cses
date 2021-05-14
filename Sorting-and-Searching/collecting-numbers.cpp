/*
 * Title: Collecting Numbers
 * Link: https://cses.fi/problemset/task/2216
 * Author: sarthak<kumar.v.sarthak@gmail.com>
 */

#include <bits/stdc++.h>
#define forl(i, a, n) for (int i = a; i < n; i++)
#define fore(i, a, n) for (int i = a; i <= n; i++)
#define forg(i, a, n) for (int i = a; i > n; i--)
#define fastio                            \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL)
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main() {
        fastio;
        int n, ans{0};
        cin >> n;
        vi ar;
        unordered_set<int> c;
        forl(i, 0, n) {
                int t;
                cin >> t;
                ar.push_back(t);
        }

        forl(i, 0, n) {
                if(ar[i] == 1 || c.count(ar[i]-1) == 0) ans++;
                c.insert(ar[i]);
        }
        cout << ans << "\n";
}