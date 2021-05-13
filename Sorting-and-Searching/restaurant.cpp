/*
 * Title: Restaurant Customers
 * Link: https://cses.fi/problemset/task/1619
 * Author: sarthak<kumar.v.sarthak@gmail.com>
 */

#include <bits/stdc++.h>

using namespace std;

struct cus {
        int t;
        char a;
};

bool cmp(cus& x, cus& y){
        return x.t < y.t;
}

int main() {
        int n, ans{0}, cnt{0};
        vector<cus> c;
        scanf("%d",&n);
        for (int i = 0; i < n; i++){
                int a,d;
                scanf("%d%d",&a,&d);
                c.push_back(cus{a,'a'});
                c.push_back(cus{d,'d'});
        }

        sort(c.begin(), c.end(), cmp);
        for (cus& i: c){
                if (i.a == 'a') cnt++;
                else cnt--;
                ans = max(ans,cnt);
        }
        printf("%d\n",ans);
}