#include <bits/stdc++.h>

using namespace std;

int main() {
        int n;
        scanf("%d", &n);

        for (long long i = 1; i <= n; i++) {
                printf("%lld\n", ((i * i * (i * i - 1)) / 2) - (4 * (i - 1) * (i - 2)));
        }
}