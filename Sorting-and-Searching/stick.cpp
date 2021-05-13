/*
 * Title: Stick Lengths
 * Link: https://cses.fi/problemset/task/1074
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

        int n;
        cin >> n;
        vi vs;
        forl(i,0,n){
                int t;
                cin >> t;
                vs.push_back(t);
        }
        sort(vs.begin(),vs.end());
        int median = vs[n/2];
        ll cost{0};
        forl(i,0,n){
                cost += abs(median - vs[i]);
        }

        cout << cost <<"\n";
}