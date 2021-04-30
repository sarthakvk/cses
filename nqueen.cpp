#include <iostream>
#include <vector>

using namespace std;

void solveQueen(int row);

int sol= 0,n;

bool *col, *dig1, *dig2;

int main() {
    cout << "Enter N: ";
    cin >> n;
    col = new bool[n];
    dig1 = new bool[2*n - 1];
    dig2 = new bool[2*n - 1];

    solveQueen(0);
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
        if (col[x] || dig1[x+row] || dig2[n+row-x-1])
            continue;
        col[x] = dig1[x+row] = dig2[n+row-x-1] = true;
        solveQueen(row + 1);
        col[x] = dig1[x+row] = dig2[n+row-x-1] = false;
    }
}
