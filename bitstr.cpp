//Your task is to calculate the number of bit strings of length n.
//For example, if n=3, the correct answer is 8, because the possible bit strings are 000, 001, 010, 011, 100, 101, 110, and 111.

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