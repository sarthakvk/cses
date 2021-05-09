#include <bits/stdc++.h>

using namespace std;

int main() {
        int n;
        scanf("%d", &n);

        vector<long long> arr;

        for (int i = 0; i < n; i++) {
                long long tmp;
                scanf("%lld", &tmp);
                arr.push_back(tmp);
        }

        long long s = 0;

        for (int i = 1; i < n; i++) {
                if (arr[i - 1] > arr[i]) {
                        s += arr[i - 1] - arr[i];
                        arr[i] = arr[i-1];
                }
        }
        cout << s << "\n";
}