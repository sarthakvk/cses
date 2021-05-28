#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define forl(i, a, n) for (auto i = a; i < n; i++)
#define fore(i, a, n) for (auto i = a; i <= n; i++)
#define forg(i, a, n) for (auto i = a; i > n; i--)
#define fastio                            \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL)
#define indexed_set(T) tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;

int main() {
        fastio;
        int n,kp;
        cin >> n >> kp;
        int k = kp % n;
        indexed_set(int) nc;
        fore(i,1,n){
                nc.insert(i);
        }
        int od = 0;
        while(!nc.empty()){
                k = kp % nc.size();
                od = (k + od)%nc.size();
                auto st = nc.find_by_order(od);
                cout << *st << " ";
                nc.erase(st);
        }
}