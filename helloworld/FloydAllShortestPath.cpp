#include <iostream>

// Floyd's All-Pair Shortest Paths

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int userNum, relationNum;
    cin >> userNum >> relationNum;

    int** matrix = new int* [userNum + 1]; // 1-indexing

    for (int i = 1; i <= userNum; i++) {
        matrix[i] = new int[userNum + 1]; // 1-indexing
        for (int j = 1; j <= userNum; j++) {
            if (i == j) {
                matrix[i][j] = 0;
                continue;
            }
            matrix[i][j] = 0xfffffff;
        }
    }

    int a, b;

    for (int i = 1; i <= relationNum; i++) {
        cin >> a >> b;
        matrix[a][b] = 1;
        matrix[b][a] = 1;
    }

    for (int k = 1; k <= userNum; k++) {
        for (int i = 1; i <= userNum; i++) {
            for (int j = 1; j <= userNum; j++) {
                if (matrix[i][k] != 0xfffffff && matrix[k][j] != 0xfffffff && matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    matrix[j][i] = matrix[i][j];
                }
            }
        }
    }

    int min {0xfffffff};
    int minIndex{0};
    for (int i = 1; i <= userNum; i++) {
        for (int j = 1; j <= userNum; j++) {
            if (i == j) 
                continue;
            matrix[i][i] += matrix[i][j];
        }
        if (min > matrix[i][i]) {
            min = matrix[i][i];
            minIndex = i;
        }
    }
    
    cout << minIndex;

    for (int i = 0; i < userNum + 1; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}