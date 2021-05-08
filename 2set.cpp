#include <bits/stdc++.h>

using namespace std;

int main() {
        int n;
        scanf("%d", &n);
        vector<int> a,b;
        long long sa{0}, sb{0};
        for (int i = n; i > 0; i--){
                if (sa <= sb){
                        a.push_back(i);
                        sa += i;
                } else{
                        b.push_back(i);
                        sb += i;
                }
        }
        if(sa == sb) {
                printf("YES\n%d\n", (int)a.size());
                for (int &i : a){
                        printf("%d ",i);
                }
                printf("\n%d\n", (int)b.size());
                for(int &i: b){
                        printf("%d ", i);
                }
        } else{
                printf("NO");
        }
        printf("\n");
}