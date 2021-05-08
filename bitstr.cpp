#include <bits/stdc++.h>
using namespace std;
long long fr(int n) {
        if (n == 0) {
                return 1LL;
        }

        if (n == 1) {
                return (2 % int(1e9 + 7));
        }

        long long t = fr(n / 2);
        t = (t * t) % int(1e9 + 7);
        if (n % 2 == 0)
                return t;
        else
                return (2 % (int)(1e9 + 7) * t) % (int)(1e9 + 7);
}

long long fr2(int n) {
        if (n == 1){
               return (2 % int(1e9 + 7)); 
        }

        long long t = fr2(n-1);

        return (2 % (int)(1e9 + 7) * t) % (int)(1e9 + 7);
}
int main() {
        int n;
        scanf("%d", &n);
        printf("%lld\n", fr(n));
}