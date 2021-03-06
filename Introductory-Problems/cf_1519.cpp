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
