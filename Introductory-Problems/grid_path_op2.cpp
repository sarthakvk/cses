#include <chrono>
#include <iostream>
#include <stack>
#include <thread>

using namespace std;

enum direction {
        N,
        S,
        E,
        W,
};

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

bool pathExist(int row, int col, direction D) {
        bool south = (D == direction::S &&
                      !isLegalMove(row + 1, col) &&
                      isLegalMove(row, col + 1) &&
                      isLegalMove(row, col - 1));

        bool north = (D == direction::N &&
                      !isLegalMove(row - 1, col) &&
                      isLegalMove(row, col + 1) &&
                      isLegalMove(row, col - 1));

        bool west = (D == direction::W &&
                     !isLegalMove(row, col - 1) &&
                     isLegalMove(row + 1, col) &&
                     isLegalMove(row - 1, col));

        bool east = (D == direction::E &&
                     !isLegalMove(row, col + 1) &&
                     isLegalMove(row + 1, col) &&
                     isLegalMove(row - 1, col));

        if (north || south || east || west)
                return false;

        return true;
}

// finding path with backtracking
void solveGrid(int row, int col, direction D) {
        updateGrid(row, col, true);
        counter++;

        if (row == n - 1 && col == n - 1) {
                if (counter == n * n) {
                        path++;
                }
        } else if (pathExist(row, col, D)) {
                if (isLegalMove(row + 1, col)) {
                        solveGrid(row + 1, col, direction::S);
                }
                if (counter > 1) {
                        if (isLegalMove(row - 1, col)) {
                                solveGrid(row - 1, col, direction::N);
                        }

                        if (isLegalMove(row, col + 1)) {
                                solveGrid(row, col + 1, direction::E);
                        }

                        if (isLegalMove(row, col - 1)) {
                                solveGrid(row, col - 1, direction::W);
                        }
                }
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
        cout << "\n";
        cout << "Enter N for finding no. of paths in NxN girid\n";
        cin >> n;

        createGrid();

        auto t1 = chrono::high_resolution_clock::now();
        solveGrid(0, 0, direction::S);
        path *= 2;
        auto t2 = chrono::high_resolution_clock::now();

        chrono::duration<double, milli> ms_double = t2 - t1;

        cout << "Execution time in sec: " << ms_double.count() / 1000 << "\n";

        freeMem();
        cout << "Paths: " << path << "\n";
}