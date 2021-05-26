/*
 * Title: Playlist
 * Link: https://cses.fi/problemset/task/1141
 * Author: sarthak<kumar.v.sarthak@gmail.com>
 */
#pragma GCC optimize("Ofast")
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
        int n,ans{-1},tans{0},start{0};
        cin >> n;
        vi s;
        unordered_map<int,int> rc(1);
        forl(i,0,n){
                int k;
                cin >> k;
                s.push_back(k);
        }
        forl(i,0,n){
                if(rc.find(s[i]) == rc.end() || rc[s[i]] < start){
                        tans++;
                        rc[s[i]] = i;
                } else{
                        ans = max(tans,ans);
                        start = rc[s[i]] + 1;
                        tans = i - start  + 1;
                        rc[s[i]] = i;
                }
        }
        ans = max(ans,tans);
        cout << ans << "\n";
}