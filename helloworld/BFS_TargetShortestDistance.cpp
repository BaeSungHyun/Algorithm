#include <iostream>
#include <queue>

using namespace std;


struct Pos {
    int row;
    int col;
    Pos(int r, int c) {
        row = r; col = c;
    }
    Pos() {
        row = 0; col = 0;
    }
};

void traverse(short** matrix, bool** visited, int R, int C, Pos& target) {
    // same graph traverse
    visited[target.row][target.col] = true;
    matrix[target.row][target.col] = 0;

    queue<Pos*> q;
    q.push(new Pos(target.row, target.col));

    while (!q.empty()) {
        Pos* current = q.front();
        q.pop();

        if (current->row + 1 < R && (!visited[current->row + 1][current->col] || matrix[current->row + 1][current->col] > matrix[current->row][current->col] + 1) 
            && matrix[current->row + 1][current->col] != 0) {
            matrix[current->row + 1][current->col] = matrix[current->row][current->col] + 1;
            if (!visited[current->row + 1][current->col]) {
                visited[current->row + 1][current->col] = true;
                q.push(new Pos(current->row + 1, current->col));
            }
        } 
        if (current->row - 1 >= 0 && (!visited[current->row - 1][current->col] || matrix[current->row - 1][current->col] > matrix[current->row][current->col] + 1)
             && matrix[current->row - 1][current->col] != 0) {
            matrix[current->row - 1][current->col] = matrix[current->row][current->col] + 1;
            if (!visited[current->row - 1][current->col]) {
                visited[current->row - 1][current->col] = true;
                q.push(new Pos(current->row - 1, current->col));
            }
        }
        if (current->col + 1 < C && (!visited[current->row][current->col + 1] || matrix[current->row][current->col + 1] > matrix[current->row][current->col] + 1)
             && matrix[current->row][current->col + 1] != 0) {
            matrix[current->row][current->col + 1] = matrix[current->row][current->col] + 1;
            if (!visited[current->row][current->col + 1]) {
                visited[current->row][current->col + 1] = true;
                q.push(new Pos(current->row, current->col + 1));
            }
        } 
        if (current->col - 1 >= 0 && (!visited[current->row][current->col - 1] || matrix[current->row][current->col - 1] > matrix[current->row][current->col] + 1)
             && matrix[current->row][current->col - 1] != 0) {
            matrix[current->row][current->col - 1] = matrix[current->row][current->col] + 1;
            if (!visited[current->row][current->col - 1]) {
                visited[current->row][current->col - 1] = true;
                q.push(new Pos(current->row, current->col - 1));
            }
        }

        delete current;
    }
}
// void func(int (&matrix)[10][10])
// void func(int (*matrix)[10], int firstDimension)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int colSize, rowSize;

    cin >> rowSize >> colSize;

    short** matrix = new short*[rowSize]; // 1000 x 1000 -- 1'000'000 integers * 4 bytes 
    bool** visited = new bool*[rowSize];

    Pos target;

    for (int i = 0; i < rowSize; i++) {
        matrix[i] = new short[colSize];
        visited[i] = new bool[colSize];
        for (int j = 0; j < colSize; j++) {
            visited[i][j] = false;
            cin >> matrix[i][j];
            if (matrix[i][j] == 0) 
                visited[i][j] = true;
            if (matrix[i][j] == 2) {
                target.row = i; 
                target.col = j;
            }
        }
    }

    traverse(matrix, visited, rowSize, colSize, target);

    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (!visited[i][j] && matrix[i][j] != 0) {
                cout << -1 << " ";
            } else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << "\n";
        delete[] matrix[i];
        delete[] visited[i];
    }

    delete[] matrix;
    delete[] visited;    
}