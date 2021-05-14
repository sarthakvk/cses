/*
 * Title: Missing Coin Sum
 * Link: https://cses.fi/problemset/task/2183
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
        vi ar;
        int n;
        cin >> n;
        forl(i, 0, n) {
                int t;
                cin >> t;
                ar.push_back(t);
        }
        sort(ar.begin(), ar.end());
        ll ans{1};

        fore(i, 0, n) {
                if (ans >= ar[i])
                        ans += ar[i];
                else
                        break;
        }
        cout << ans << "\n";
}