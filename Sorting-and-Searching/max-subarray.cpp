/*
 * Title: Maximum Subarray Sum
 * Link: https://cses.fi/problemset/task/1643
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
        int n;
        vi arr;
        cin >> n;
        forl(i, 0, n) {
                int t;
                cin >> t;
                arr.push_back(t);

        }
        ll ms{arr[0]}, ts{arr[0]};
        forl(i, 1, n) {
                ts = max(ts + arr[i], (ll)arr[i]);
                ms = max(ms, ts);
        }
        cout << ms << "\n";
}