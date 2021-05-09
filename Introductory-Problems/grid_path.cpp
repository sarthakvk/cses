#include <chrono>
#include <iostream>
#include <stack>
#include <thread>

using namespace std;

unsigned int path{0};

int n, counter;

bool** grid;

void createGrid() {
        grid = new bool* [n] {};
        for (int i = 0; i < n; ++i) {
                grid[i] = new bool[n];
        }

        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        grid[i][i] = false;
                }
        }
}

void updateGrid(int row, int col, bool val) {
        grid[row][col] = val;
}

bool isLegalMove(int row, int col) {
        if ((row < n && row >= 0) && (col < n && col >= 0) && !grid[row][col]) {
                return true;
        }
        return false;
}

void printGrid() {
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        cout << grid[i][j] << "   ";
                }
                cout << "\n";
        }
        cout << "\n";
}

// Backtracking with no optimizations, to find the number of paths
// we simply use backtracking to generate all possible path from start to end.
void solveGrid(int row, int col) {
        updateGrid(row, col, true);
        counter++;

        if (row == n - 1 && col == n - 1) {
                if (counter == n * n) {
                        path++;
                        printf("%d\n", path);
                }
                updateGrid(row, col, false);
                counter--;
                return;
        }

        if (isLegalMove(row + 1, col))
                solveGrid(row + 1, col);

        if (isLegalMove(row - 1, col))
                solveGrid(row - 1, col);

        if (isLegalMove(row, col + 1))
                solveGrid(row, col + 1);

        if (isLegalMove(row, col - 1))
                solveGrid(row, col - 1);

        updateGrid(row, col, false);
        counter--;
}

// In this we optimize `solveGrid` to start with fixed move
// that is row down and simply divide the solutions found by `2`.
void solveGrid2(int row, int col) {
        updateGrid(row, col, true);
        counter++;

        if (row == n - 1 && col == n - 1) {
                if (counter == n * n)
                        path++;

                updateGrid(row, col, false);
                counter--;
                return;
        }

        if (isLegalMove(row + 1, col))
                solveGrid(row + 1, col);
        if (counter > 1) {
                if (isLegalMove(row - 1, col))
                        solveGrid(row - 1, col);

                if (isLegalMove(row, col + 1))
                        solveGrid(row, col + 1);

                if (isLegalMove(row, col - 1))
                        solveGrid(row, col - 1);
        }
        updateGrid(row, col, false);
        counter--;
}

void freeMem() {
        for (int i = 0; i < n; i++)
                free(grid[i]);
        free(grid);
}

int main() {
        cout << "Enter N for finding no. of paths in NxN girid\n";
        cin >> n;

        createGrid();

        auto t1 = chrono::high_resolution_clock::now();
        solveGrid(0, 0);
        auto t2 = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> ms_double = t2 - t1;

        cout << "Execution time in ms: " << ms_double.count() << "\n";

        freeMem();
        cout << "Paths: " << path << "\n";
}