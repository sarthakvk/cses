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
        list<int> ls;
        fore(i, 1, n) {
                ls.push_back(i);
        }
        if (n == 1) {
                cout << *ls.begin();
                return 0;
        }
        auto st = ++ls.begin();
        while (!ls.empty()) {
                cout << *st << " ";
                st = ls.erase(st);
                if(st == ls.end()) st = ls.begin();
                ++st;
                if(st == ls.end()) st = ls.begin();
        }
}