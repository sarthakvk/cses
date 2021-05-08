//The Tower of Hanoi game consists of three stacks (left, middle and right)
//and n round disks of different sizes. Initially, the left stack has all the disks,
//in increasing order of size from top to bottom.

//The goal is to move all the disks to the right stack using the middle stack.
//On each move you can move the uppermost disk from a stack to another stack.
//In addition, it is not allowed to place a larger disk on a smaller disk.

//Your task is to find a solution that minimizes the number of moves.

#include <bits/stdc++.h>

using namespace std;

long long cm{0};
vector<vector<int>> out;

void toh(int i, int a, int b, int c) {
        if (i == 1) {
                cm++;
                out.push_back({a,b});
                return;
        }
        toh(i - 1, a, c, b);
        cm++;
        out.push_back({a,b});
        toh(i - 1, c, b, a);
}

int main() {
        int n;
        scanf("%d", &n);
        toh(n, 1, 3, 2);
        printf("%d\n",cm);
        for(auto &i: out){
                printf("%d %d\n",i[0],i[1]);
        }

}