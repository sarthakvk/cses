// Polycarp is an organizer of a Berland ICPC regional event. There are 𝑛 universities in Berland numbered from 1 to 𝑛.
// Polycarp knows all competitive programmers in the region. There are 𝑛 students: the 𝑖-th student is enrolled at a university 𝑢𝑖 and has a programming skill 𝑠𝑖
// Polycarp has to decide on the rules now. In particular, the number of members in the team.
// Polycarp knows that if he chooses the size of the team to be some integer 𝑘
// , each university will send their 𝑘 strongest (with the highest programming skill 𝑠) students in the first team,
// the next 𝑘 strongest students in the second team and so on. If there are fewer than 𝑘

// students left, then the team can't be formed. Note that there might be universities that send zero teams.

// The strength of the region is the total skill of the members of all present teams. If there are no teams present, then the strength is 0

// Help Polycarp to find the strength of the region for each choice of 𝑘
// from 1 to 𝑛

// Input

// The first line contains a single integer 𝑡
// (1≤𝑡≤1000) — the number of testcases.

// The first line of each testcase contains a single integer 𝑛
// (1≤𝑛≤2⋅105 ) — the number of universities and the number of students.

// The second line of each testcase contains 𝑛
// integers 𝑢1,𝑢2,…,𝑢𝑛 (1≤𝑢𝑖≤𝑛) — the university the 𝑖-th student is enrolled at.

// The third line of each testcase contains 𝑛
// integers 𝑠1,𝑠2,…,𝑠𝑛 (1≤𝑠𝑖≤109) — the programming skill of the 𝑖-th student.

// The sum of 𝑛
// over all testcases doesn't exceed 2⋅105

// Output

// For each testcase print 𝑛
// integers: the strength of the region — the total skill of the members of the present teams — for each choice of team size 𝑘.

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
