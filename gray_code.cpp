//A Gray code is a list of all 2n bit strings of length n,
//where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
//Your task is to create a Gray code for a given length n.

#include <bits/stdc++.h>

using namespace std;
int n;
vector<string> l1, l2;

void gc(int i) {
        if (i == 1) {
                l1.push_back("0");
                l1.push_back("1");
        } else {
                gc(i - 1);
                l2.assign(l1.rbegin(), l1.rend());

                for (int i = 0; i < (int)l1.size(); i++) {
                        l1[i] = "0" + l1[i];
                }
                for (int i = 0; i < (int)l2.size(); i++) {
                        l2[i] = "1" + l2[i];
                }
                for (int i = 0; i < (int)l2.size(); i++) {
                        l1.push_back(l2[i]);
                }
        }
}

int main() {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        scanf("%d", &n);
        gc(n);
        for (auto &i : l1) {
                cout << i << "\n";
        }
}