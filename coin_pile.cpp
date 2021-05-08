//You have two coin piles containing a and b coins.
//On each move, you can either remove one coin from the left pile and two coins from the right pile,
//or two coins from the left pile and one coin from the right pile.
//Your task is to efficiently find out if you can empty both the piles.

#include <bits/stdc++.h>

using namespace std;

int main() {
        int t;
        cin >> t;
        while (t--) {
                int a, b;
                scanf("%d%d", &a, &b);

                if ((a + b) % 3 == 0 && abs(a - b) <= min(a,b))
                        cout << "YES\n";
                else
                        cout << "NO\n";
        }
}