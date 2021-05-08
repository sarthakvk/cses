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