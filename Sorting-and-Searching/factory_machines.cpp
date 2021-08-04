#include <bits/stdc++.h>
#define forl(i, a, n) for (auto i = a; i < n; i++)
#define fore(i, a, n) for (auto i = a; i <= n; i++)
#define forg(i, a, n) for (auto i = a; i > n; i--)
#define fastio                            \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

bool pg(ull t, ull pn, vector<ull>& k) {
        ull p = 0;
        for (auto& i : k) {
                p += t / i;
        }
        return p >= pn;
}

int main() {
        fastio;
        ull n, t;
        cin >> n >> t;
        vector<ull> k;
        forl(i, 0, n) {
                ull t;
                cin >> t;
                k.push_back(t);
        }
        ull p = 0, m = k[0] * t;

        for (ull b = m; b >= 1; b /= 2) {

                while (!pg(p + b, t, k))
                {
                        p += b;
                }
        }
        cout << p + 1;
}