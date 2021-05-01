#include <iostream>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

int sol = 0, n;

bool *col, *dig1, *dig2;
// unordered_set<int> col_av, dig1_av, dig2_av;

void createTable() {
        for (int i = 0; i < n; i++) {
                col[i] = false;
        }

        for (int i = 0; i < 2 * n - 1; i++) {
                dig1[i] = false;
                dig2[i] = false;
        }
}

void insertTable(int row, int x) {
        col[x] = 1;
        dig1[row + x] = 1;
        dig2[n + row - x - 1] = 1;
}

void popTable(int row, int x) {
        col[x] = 0;
        dig1[row + x] = 0;
        dig2[n + row - x - 1] = 0;
}

stack<int> findColoumn(int row) {
        stack<int> col_av;

        for (int i = 0; i < n; i++) {
                if (!(col[i] || dig1[row + i] || dig2[n + row - i - 1])) {
                        // cout << "Found position: " << i << " Row: " << row << "\n";
                        col_av.push(i);
                }
        }
        return col_av;
}

void solveQueen(int row) {
        if (row == n) {
                sol++;
                return;
        }

        stack<int> x = findColoumn(row);

        while (!x.empty()) {
                int i = x.top();
                x.pop();
                insertTable(row, i);
                solveQueen(row + 1);
                popTable(row, i);
        }
}

int main() {
        cout << "Enter N: ";
        cin >> n;
        col = new bool[n];
        dig1 = new bool[2 * n - 1];
        dig2 = new bool[2 * n - 1];
        createTable();
        // cout << sizeof(bitfeild);
        solveQueen(0);
        free(col);
        free(dig1);
        free(dig2);
        cout << "Number of Solutions: " << sol << "\n";
}
