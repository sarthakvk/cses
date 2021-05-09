//Your task is to calculate the number of trailing zeros in the factorial n!.
//For example, 20!=2432902008176640000 and it has 4 trailing zeros.

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