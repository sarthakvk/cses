#include <iostream>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

vector<set<int>> w_set;

void findSubSet(int n) {
        w_set.clear();
        for (int b = 0; b < (1 << n); b++) {
                set<int> t_set;
                for (int i = 0; i < n; i++) {
                        if (b & (1 << i)) {
                                t_set.insert(i);
                        }
                }
                w_set.push_back(t_set);
        }
}

int main() {
        int x;
        string str;
        vector<int> vecA, vecB, vecA_sum, vecB_sum;
        cout << "Enter the list of int seperated with space: \n";
        getline(cin >> ws, str);

        cout << "Enter the value of x: ";
        cin >> x;

        istringstream reader(str);

        while (!reader.eof()) {
                int n;
                reader >> n;
                vecA.push_back(n);
                if (!reader.eof()) {
                        reader >> n;
                        vecB.push_back(n);
                }
        }
        findSubSet(vecA.size());
        for(auto &i: w_set) {
                int sum = 0;
                for (auto &j : i) {
                        sum += vecA[j];
                }
                vecA_sum.push_back(sum);
        }

        findSubSet(vecB.size());
        for(auto &i: w_set) {
                int sum = 0;
                for (auto &j : i) {
                        sum += vecB[j];
                }
                vecB_sum.push_back(sum);
        }

        for (int &i : vecA_sum)
                cout << i << " ";
        cout << "\n";
        for (int &i : vecB_sum)
                cout << i << " ";

}