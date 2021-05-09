#include <bits/stdc++.h>

using namespace std;

int main() {
        char str[1000000], prev = '\0';
        scanf("%s", str);
        int max{0}, count{0};
        prev = str[0];
        int i = 1;
        while (str[i] != '\0') {
                if (str[i] == prev) {
                        count++;
                } else {
                        count = 0;
                }
                max = max > count ? max : count;
                prev = str[i];
                i += 1;
        }
        cout << max + 1 << "\n";
}