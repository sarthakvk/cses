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
        int x, n;
        vi l;
        map<int, int> s;
        multiset<int> a;
        cin >> x >> n;
        forl(i, 0, n) {
                int t;
                cin >> t;
                l.push_back(t);
        }
        s[0] = x;
        a.insert(x);
        forl(i, 0, n) {
                auto ins = s.lower_bound(l[i]);
                ins--;
                int t = (*ins).second;
                s[l[i]] = t - (l[i] - (*ins).first);
                (*ins).second = l[i] - (*ins).first;
                a.erase(a.lower_bound(t));
                a.insert((*ins).second);
                a.insert(s[l[i]]);
                cout << (*(--a.end())) << " ";
        }
}