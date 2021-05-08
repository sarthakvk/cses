#include <iostream>

using namespace std;

int main() {
        int t;
        scanf("%d", &t);
        while (t--) {
                long long i, j;
                scanf("%lld%lld", &i, &j);
                long long rs, cs;
                bool r, c;
                if (i % 2 == 0) {
                        rs = i * i;
                        r = true;
                } else {
                        rs = (i - 1) * (i - 1) + 1;
                        r = false;
                }
                if (j % 2 != 0) {
                        cs = j * j;
                        c = false;
                } else {
                        cs = (j - 1) * (j - 1) + 1;
                        c = true;
                }

                if (i >= j) {
                        if (r)
                                printf("%lld\n", rs - j + 1);
                        else
                                printf("%lld\n", rs + j - 1);
                } else {
                        if (c)
                                printf("%lld\n", cs + i - 1);
                        else
                                printf("%lld\n", cs - i + 1);
                }
        }
}