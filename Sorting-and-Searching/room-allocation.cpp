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
        int room = 0;
        map<pair<int,int>, int> m;
        cin >> n;
        vector<array<int,3>> v(n);
        vi out(n);
        forl(i, 0, n){
                cin >> v[i][0] >> v[i][1];
                v[i][2] = i;
        }
        sort(v.begin(), v.end());

        forl(i,0,n){
                auto lb = m.lower_bound({v[i][0],-1});
                if (lb == m.begin()){
                        room++;
                        out[v[i][2]] = room;
                        m[{v[i][1],v[i][2]}] = room;
                }
                else {
                        out[v[i][2]] = (*m.begin()).second;
                        m.erase(m.begin());
                        m[{v[i][1],v[i][2]}] = out[v[i][2]];
                }
        }
        cout << room << "\n";
        forl(i,0,n){
                cout << out[i] << " ";
        }
}