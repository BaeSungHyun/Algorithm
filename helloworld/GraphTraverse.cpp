#include <iostream>
#include <queue>

using namespace std;

struct coordinate{
    int x;
    int y;
    coordinate(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

void traverse(int mat[100][100], bool v[100][100], int row, int col) {
    queue<coordinate*> q;

    q.push(new coordinate(0,0));
    v[0][0] = true;

    while (!q.empty()) {
        coordinate* temp = q.front();
        q.pop();

        if (temp->x - 1 >= 0 && mat[temp->x - 1][temp->y] == 1 && v[temp->x - 1][temp->y] == false) {
            mat[temp->x - 1][temp->y] = mat[temp->x][temp->y] + 1;
            v[temp->x - 1][temp->y] = true;
            q.push(new coordinate(temp->x - 1, temp->y));
        }
        if (temp->x + 1 <  row && mat[temp->x + 1][temp->y] == 1 && v[temp->x + 1][temp->y] == false) {
            mat[temp->x + 1][temp->y] = mat[temp->x][temp->y] + 1;
            v[temp->x + 1][temp->y] == true;
            q.push(new coordinate(temp->x + 1, temp->y));
        }
        if (temp->y - 1 >= 0 && mat[temp->x][temp->y - 1] == 1 && v[temp->x][temp->y - 1] == false) {
            mat[temp->x][temp->y - 1] = mat[temp->x][temp->y] + 1;
            v[temp->x][temp->y - 1] == true;
            q.push(new coordinate(temp->x, temp->y - 1));
        }
        if (temp->y + 1 < col && mat[temp->x][temp->y + 1] == 1 && v[temp->x][temp->y + 1] == false) {
            mat[temp->x][temp->y + 1] = mat[temp->x][temp->y] + 1;
            v[temp->x][temp->y + 1] == true;
            q.push(new coordinate(temp->x, temp->y + 1));
        }

        if (mat[row - 1][col - 1] != 1) {
            return;
        }

        delete temp;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col;
    cin >> row >> col;

    int matrix[100][100]; // zero-indexing
    bool visited[100][100];

    char t[101];
    for (int r = 0; r < row; r++) {
        cin >> t;
        for (int c = 0; c < col; c++) {
            matrix[r][c] = (int)(t[c] - '0');
            visited[r][c] = false;
        }
    }

    traverse(matrix, visited, row, col);

    cout << matrix[row - 1][col - 1];
}