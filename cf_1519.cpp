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

#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <chrono>

using namespace std;

int main() {

        auto s = chrono::high_resolution_clock::now();
        int t;
        scanf("%d", &t);

        for (int i = 0; i < t; i++) {
                int n;
                unordered_map<int, priority_queue<int>> stud;
                string ui, si;
                vector<int> v_ui, v_si;
                scanf("%d", &n);
                {
                        char line[4000000];
                        scanf(" %[^\n]", line);
                        ui = line;
                        scanf(" %[^\n]", line);
                        si = line;

                        istringstream iss(ui);
                        v_ui.assign(istream_iterator<int>(iss), istream_iterator<int>());
                        istringstream iss2(si);
                        v_si.assign(istream_iterator<int>(iss2), istream_iterator<int>());
                }

                for (int j = 0; j < n; j++) {
                        stud[v_ui[j]].push(v_si[j]);
                }

                for (int k = 1; k <= n; k++) {
                        int sum{0};
                        for (auto it = stud.begin(); it != stud.end(); it++) {
                                int j = it->first;
                                vector<int> tmp;
                                while (stud[j].size() >= k) {
                                        for (int x = 0; x < k; x++) {
                                                sum += stud[j].top();
                                                tmp.push_back(stud[j].top());
                                                stud[j].pop();
                                        }
                                }
                                while (!tmp.empty()) {
                                        stud[j].push(*(tmp.end() - 1));
                                        tmp.pop_back();
                                }
                        }
                        printf("%d ", sum);
                }
                printf("\n");
        }
                auto e = chrono::high_resolution_clock::now();

                auto time = chrono::duration_cast<chrono::milliseconds>(e-s);
                cout << "Execution Time: "<<time.count() << "\n";
}
