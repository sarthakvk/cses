//Given a string, your task is to reorder its letters in such a way that it becomes a palindrome
//(i.e., it reads the same forwards and backwards).

#include <bits/stdc++.h>

using namespace std;

int main() {
        char st[1000000];
        scanf("%s", st);
        string s = st, o;
        int n = (int)s.size();
        char odd = '\0';
        bool bs = false;
        int start{1};
        sort(s.begin(), s.end());
        for (int i = 0; i < n; i += 2) {
                if (s[i] == s[i + 1]) {
                        o.push_back(s[i]);
                } else if (odd != '\0') {
                        printf("NO SOLUTION\n");
                        return 0;
                } else {
                        odd = s[i];
                        i--;
                }
        }
        if (odd != '\0') {
                bs = true;
                o.push_back(odd);
        }

        if (bs)
                start += 1;

        for (auto i = (int)o.size() - start; i >= 0; i--) {
                o.push_back(o[i]);
        }

        cout << o << "\n";
}