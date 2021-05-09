//Your task is to count for k=1,2,…,n the number of ways two knights can be placed on a k×k chessboard
//so that they do not attack each other.
#include <bits/stdc++.h>

using namespace std;

int main() {
        int n;
        scanf("%d", &n);

        for (long long i = 1; i <= n; i++) {
                printf("%lld\n", ((i * i * (i * i - 1)) / 2) - (4 * (i - 1) * (i - 2)));
        }
}