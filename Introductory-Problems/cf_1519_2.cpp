// Polycarp is an organizer of a Berland ICPC regional event. There are ๐ universities in Berland numbered from 1 to ๐.
// Polycarp knows all competitive programmers in the region. There are ๐ students: the ๐-th student is enrolled at a university ๐ข๐ and has a programming skill ๐ ๐
// Polycarp has to decide on the rules now. In particular, the number of members in the team.
// Polycarp knows that if he chooses the size of the team to be some integer ๐
// , each university will send their ๐ strongest (with the highest programming skill ๐ ) students in the first team,
// the next ๐ strongest students in the second team and so on. If there are fewer than ๐

// students left, then the team can't be formed. Note that there might be universities that send zero teams.

// The strength of the region is the total skill of the members of all present teams. If there are no teams present, then the strength is 0

// Help Polycarp to find the strength of the region for each choice of ๐
// from 1 to ๐

// Input

// The first line contains a single integer ๐ก
// (1โค๐กโค1000) โ the number of testcases.

// The first line of each testcase contains a single integer ๐
// (1โค๐โค2โ105 ) โ the number of universities and the number of students.

// The second line of each testcase contains ๐
// integers ๐ข1,๐ข2,โฆ,๐ข๐ (1โค๐ข๐โค๐) โ the university the ๐-th student is enrolled at.

// The third line of each testcase contains ๐
// integers ๐ 1,๐ 2,โฆ,๐ ๐ (1โค๐ ๐โค109) โ the programming skill of the ๐-th student.

// The sum of ๐
// over all testcases doesn't exceed 2โ105

// Output

// For each testcase print ๐
// integers: the strength of the region โ the total skill of the members of the present teams โ for each choice of team size ๐.

#include <algorithm>
#include <iostream>
#include <vector>

#define forn(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main() {
        int t;
        scanf("%d", &t);

        forn(_, t) {
                int n;
                scanf("%d", &n);
                vector<vector<unsigned long long>> stud(n);
                vector<int> s(n), u(n);
                vector<long long> ans(n);
                forn(i, n) {
                        scanf("%d", &u[i]);
                        --u[i];
                }

                forn(i, n)
                    scanf("%d", &s[i]);

                forn(i, n)
                    stud[u[i]]
                        .push_back(s[i]);

                forn(i, n)
                    sort(stud[i].rbegin(), stud[i].rend());

                forn(i, (int)stud.size()) {
                        unsigned long long sum{0};
                        forn(j, (int)stud[i].size()) {
                                sum += stud[i][j];
                                stud[i][j] = sum;
                        }
                }

                forn(i, n) {
                        for (int k = 1; k <= (int)stud[i].size(); k++) {
                                unsigned long long sum{0};
                                if ((int)stud[i].size() >= k) {
                                        ans[k - 1] += stud[i][(int)stud[i].size() - (int)stud[i].size() % k - 1];
                                }
                        }
                }
                forn(i,n)
                printf("%lld ",ans[i]);
        }
        printf("\n");
}
