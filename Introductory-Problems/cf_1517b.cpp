/* The 2050 volunteers are organizing the "Run! Chase the Rising Sun" activity.
Starting on Apr 25 at 7:30 am, runners will complete the 6km trail around the Yunqi town.

There are π+1
checkpoints on the trail. They are numbered by 0, 1, ..., π.
A runner must start at checkpoint 0 and finish at checkpoint π. No checkpoint is skippable β
he must run from checkpoint 0 to checkpoint 1, then from checkpoint 1 to checkpoint 2

and so on. Look at the picture in notes section for clarification.

Between any two adjacent checkpoints, there are π
different paths to choose. For any 1β€πβ€π, to run from checkpoint πβ1 to checkpoint π,
a runner can choose exactly one from the π possible paths.
The length of the π-th path between checkpoint πβ1 and π is ππ,π for any 1β€πβ€π and 1β€πβ€π

.

To test the trail, we have π
runners. Each runner must run from the checkpoint 0 to the checkpoint π once, visiting all the checkpoints.
Every path between every pair of adjacent checkpoints needs to be ran by exactly one runner.
If a runner chooses the path of length ππ between checkpoint πβ1 and π (1β€πβ€π), his tiredness is

minπ=1πππ,

i. e. the minimum length of the paths he takes.

Please arrange the paths of the π

runners to minimize the sum of tiredness of them.
Input

Each test contains multiple test cases. The first line contains the number of test cases π‘
(1β€π‘β€10000

). Description of the test cases follows.

The first line of each test case contains two integers π
and π (1β€π,πβ€100

).

The π
-th of the next π lines contains π integers ππ,1, ππ,2, ..., ππ,π (1β€ππ,πβ€109

).

It is guaranteed that the sum of πβπ
over all test cases does not exceed 104

.
Output

For each test case, output π
lines. The π-th number in the π-th line should contain the length of the path that runner π chooses to run from checkpoint πβ1 to checkpoint π. There should be exactly π integers in the π-th line and these integers should form a permuatation of ππ,1, ..., ππ,π for all 1β€πβ€π

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