// TODO: redo
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#define forl(i, a, n) for (auto i = a; i < n; i++)
#define fore(i, a, n) for (auto i = a; i <= n; i++)
#define forg(i, a, n) for (auto i = a; i > n; i--)
#define fastio                            \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL)
#define inp(n, type) \
        type n;      \
        cin >> n;
using namespace std;
using namespace __gnu_pbds;
using namespace std;
template <class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef vector<int> vi;

int main() {
        fastio;
        int n;
        cin >> n;
        vector<array<int, 3>> r;
        vi A(n,0),B(n,0);
        multiset<int> is;
        forl(i, 0, n) {
                int x, y;
                cin >> x >> y;
                r.push_back({x, y, i});
        }
        sort(r.begin(), r.end(), [&](auto& i, auto& j) {
                return i[0] < j[0] || (i[0] == j[0] && i[1] > j[1]);
        });
        int mrb = 0;
        for (auto& i : r) {
                if (mrb >= i[1]) B[i[2]] = 1;
                else mrb = i[1];
        }
        int lrb = numeric_limits<int>::max();
        for(auto i = r.rbegin(); i != r.rend(); i++){
                if (lrb <= (*i)[1]) A[(*i)[2]] = 1;
                else lrb = (*i)[1];
        }

        for(auto& i : A) cout << i << " ";
        cout << "\n";
        for(auto& i : B) cout << i << " ";
}