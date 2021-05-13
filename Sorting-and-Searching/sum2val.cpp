/*
 * Title: Sum of Two Values
 * Link: https://cses.fi/problemset/task/1640
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

struct vals{
        int i;
        int v;
};

bool cmp(vals& a, vals& b){
        return a.v < b.v;
}
bool cmp2(vals& a, int b){
        return a.v < b;
}

int main() {
        fastio;
        int n, x;
        cin >> n >> x;
        vector<vals> a;

        forl(i, 0, n) {
                int t;
                cin >> t;
                a.push_back(vals{i+1,t});
        }

        sort(a.begin(), a.end(),cmp);

        forl(i, 0, n) {
                int p = lower_bound(a.begin(), a.end(), x - a[i].v, cmp2) - a.begin();
                if (a[p].v + a[i].v == x && p != i) {
                        cout << a[i].i << " " << a[p].i << "\n";
                        return 0;
                }
        }
        cout << "IMPOSSIBLE\n";
}