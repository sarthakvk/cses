#include <bits/stdc++.h>

using namespace std;

int main() {
        int n, five{0};
        scanf("%d", &n);
        while (n){
                five += n/5;
                n /= 5;
        }
        printf("%d\n",five);
}