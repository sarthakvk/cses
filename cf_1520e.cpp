/*You are playing the game "Arranging The Sheep". The goal of this game is to make the sheep line up.
The level in the game is described by a string of length 𝑛

, consisting of the characters '.' (empty space) and '*' (sheep).
In one move, you can move any sheep one square to the left or one square to the right,
if the corresponding square exists and is empty. The game ends as soon as the sheep are lined up, that is,
there should be no empty cells between any sheep.

For example, if 𝑛=6

and the level is described by the string "**.*..", then the following game scenario is possible:

    the sheep at the 4

position moves to the right, the state of the level: "**..*.";
the sheep at the 2
position moves to the right, the state of the level: "*.*.*.";
the sheep at the 1
position moves to the right, the state of the level: ".**.*.";
the sheep at the 3
position moves to the right, the state of the level: ".*.**.";
the sheep at the 2

    position moves to the right, the state of the level: "..***.";
    the sheep are lined up and the game ends. 

For a given level, determine the minimum number of moves you need to make to complete the level.
Input

The first line contains one integer 𝑡
(1≤𝑡≤104). Then 𝑡

test cases follow.

The first line of each test case contains one integer 𝑛
(1≤𝑛≤106

).

The second line of each test case contains a string of length 𝑛

, consisting of the characters '.' (empty space) and '*' (sheep) — the description of the level.

It is guaranteed that the sum of 𝑛
over all test cases does not exceed 106

.
Output

For each test case output the minimum number of moves you need to make to complete the level.
*/

#include <iostream>
#include <vector>

#define forn(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
        int t;
        scanf("%d", &t);
        forn(_, t) {
                int n{0}, count{0}, mid{0}, prev{0}, mul{0};
                long long sum{0};
                vector<int> dist(n);
                char str[1000000];
                scanf("%d", &n);
                scanf("%s", str);

                forn(i, n) {
                        if (str[i] == '*') {
                                dist.push_back(i - prev - 1);
                                prev = i;
                                count++;
                        }
                }
                mid = count / 2 + 1;

                forn(i, count) {
                        if (i == mid) {
                                mul = count - mid;
                        }

                        sum += mul * dist[i];

                        if (i >= mid)
                                mul--;
                        else
                                mul++;
                }
                printf("%lld\n", sum);
        }
}
