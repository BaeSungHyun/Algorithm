#include <iostream>

using namespace std;

void recursive(int** matrix, int size, int leftCornerRow, int leftCornerCol, int& white, int& blue) {
    bool whiteB = false; 
    bool blueB = false;
    for (int i = leftCornerRow; i < leftCornerRow + size; i++) {
        for (int j = leftCornerCol; j < leftCornerCol + size; j ++) {
            if (matrix[i][j] == 0)
                whiteB = true;
            if (matrix[i][j] == 1) 
                blueB = true;
            if (whiteB && blueB) {
                whiteB = false;
                blueB = false;
                recursive(matrix, size / 2, leftCornerRow, leftCornerCol, white, blue);
                recursive(matrix, size / 2, leftCornerRow + size / 2, leftCornerCol, white, blue);
                recursive(matrix, size / 2, leftCornerRow, leftCornerCol + size / 2, white, blue);
                recursive(matrix, size / 2, leftCornerRow + size / 2, leftCornerCol + size / 2, white, blue);
                return;
            }
        }
    }

    if (whiteB) white++;
    if (blueB) blue++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int** matrix = new int*[N]; // 0 ~ 63 , 64 ~ 127
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    int white {0};
    int blue {0};
    recursive(matrix, N, 0, 0, white, blue);

    cout << white << "\n";
    cout << blue;
}