#include <iostream>
#include <vector>

using namespace std;

void solveQueen(int row);

int sol = 0, n;

struct bitfeild {
        bool val : 1;
};

bitfeild *col, *dig1, *dig2;

int main() {
        cout << "Enter N: ";
        cin >> n;
        col = new bitfeild[n];
        dig1 = new bitfeild[2 * n - 1];
        dig2 = new bitfeild[2 * n - 1];
        cout << sizeof(bitfeild);
        // solveQueen(0);
        free(col);
        free(dig1);
        free(dig2);
        cout << "Number of Solutions: " << sol << "\n";
}

void solveQueen(int row) {
        // if current row is n the we have found the solution
        if (row == n) {
                sol++;
                return;
        }
        // looping to check coloumn for queen
        for (int x = 0; x < n; x++) {
                if (col[x].val || dig1[x + row].val || dig2[n + row - x - 1].val)
                        continue;
                col[x].val = dig1[x + row].val = dig2[n + row - x - 1].val = true;
                solveQueen(row + 1);
                col[x].val = dig1[x + row].val = dig2[n + row - x - 1].val = false;
        }
}
