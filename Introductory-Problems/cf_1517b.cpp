/* The 2050 volunteers are organizing the "Run! Chase the Rising Sun" activity.
Starting on Apr 25 at 7:30 am, runners will complete the 6km trail around the Yunqi town.

There are 𝑛+1
checkpoints on the trail. They are numbered by 0, 1, ..., 𝑛.
A runner must start at checkpoint 0 and finish at checkpoint 𝑛. No checkpoint is skippable —
he must run from checkpoint 0 to checkpoint 1, then from checkpoint 1 to checkpoint 2

and so on. Look at the picture in notes section for clarification.

Between any two adjacent checkpoints, there are 𝑚
different paths to choose. For any 1≤𝑖≤𝑛, to run from checkpoint 𝑖−1 to checkpoint 𝑖,
a runner can choose exactly one from the 𝑚 possible paths.
The length of the 𝑗-th path between checkpoint 𝑖−1 and 𝑖 is 𝑏𝑖,𝑗 for any 1≤𝑗≤𝑚 and 1≤𝑖≤𝑛

.

To test the trail, we have 𝑚
runners. Each runner must run from the checkpoint 0 to the checkpoint 𝑛 once, visiting all the checkpoints.
Every path between every pair of adjacent checkpoints needs to be ran by exactly one runner.
If a runner chooses the path of length 𝑙𝑖 between checkpoint 𝑖−1 and 𝑖 (1≤𝑖≤𝑛), his tiredness is

min𝑖=1𝑛𝑙𝑖,

i. e. the minimum length of the paths he takes.

Please arrange the paths of the 𝑚

runners to minimize the sum of tiredness of them.
Input

Each test contains multiple test cases. The first line contains the number of test cases 𝑡
(1≤𝑡≤10000

). Description of the test cases follows.

The first line of each test case contains two integers 𝑛
and 𝑚 (1≤𝑛,𝑚≤100

).

The 𝑖
-th of the next 𝑛 lines contains 𝑚 integers 𝑏𝑖,1, 𝑏𝑖,2, ..., 𝑏𝑖,𝑚 (1≤𝑏𝑖,𝑗≤109

).

It is guaranteed that the sum of 𝑛⋅𝑚
over all test cases does not exceed 104

.
Output

For each test case, output 𝑛
lines. The 𝑗-th number in the 𝑖-th line should contain the length of the path that runner 𝑗 chooses to run from checkpoint 𝑖−1 to checkpoint 𝑖. There should be exactly 𝑚 integers in the 𝑖-th line and these integers should form a permuatation of 𝑏𝑖,1, ..., 𝑏𝑖,𝑚 for all 1≤𝑖≤𝑛

.

If there are multiple answers, print any.
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
        int t;
        scanf("%d", &t);
        forn(_, t) {
                int n, m;
                scanf("%d %d", &n, &m);
                vector<vector<int>> p(n), ans(n);

                forn(i, n) {
                        forn(j, m) {
                                int tmp;
                                scanf("%d", &tmp);
                                p[i].push_back(tmp);
                        }
                        sort(p[i].begin(), p[i].end());
                }

                forn(k,m) {
                        int min{0}, i{0};
                        for (i = 0; i < n; i++) {
                                min = *p[i].begin() < *p[min].begin() ? i : min;
                        }
                        ans[min].push_back(*p[min].begin());
                        p[min].erase(p[min].begin());

                        forn(j, n) {
                                if (j != min) {
                                        ans[j].push_back(*(p[j].end()-1));
                                        p[j].pop_back();
                                }
                        }
                }
                forn(i, n) {
                        forn(j, m) {
                                printf("%d ", ans[i][j]);
                        }
                        printf("\n");
                }
        }
}