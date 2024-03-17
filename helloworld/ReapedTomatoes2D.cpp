// 26904 KB , 124 ms

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int row, col;
    cin >> col >> row;

    queue<int*> candidates;
    int queNum;

    int tomatoes{0};

    int** matrix = new int*[row];
    bool** boolM = new bool*[row];

    for (int i = 0; i < row; i++) {
        matrix[i] = new int[col];
        boolM[i] = new bool[col];
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];

            boolM[i][j] = false;
            if (matrix[i][j] == 1) {
                candidates.push(new int[2] {i, j});
            }

            if (matrix[i][j] == 0) {
                tomatoes++;
            } 
        }
    }

    int days{0};
    queNum = (int)candidates.size();

    bool changed {false};

    while (!candidates.empty()) {
        int* temp = candidates.front();
        int curRow = temp[0];
        int curCol = temp[1];
        candidates.pop();
        delete[] temp;

        queNum--;

        if (boolM[curRow][curCol] == false) {
            // check up, down, left, right
            if (curRow + 1 < row && matrix[curRow + 1][curCol] == 0) {
                matrix[curRow + 1][curCol] = 1;
                candidates.push(new int[2] {curRow + 1, curCol});
                changed = true;
                tomatoes--;
            }
            if (curRow - 1 >= 0 && matrix[curRow - 1][curCol] == 0) {
                matrix[curRow - 1][curCol] = 1;
                candidates.push(new int[2] {curRow - 1, curCol});
                changed = true;
                tomatoes--;
            }
            if (curCol + 1 < col && matrix[curRow][curCol + 1] == 0) {
                matrix[curRow][curCol + 1] = 1;
                candidates.push(new int[2] {curRow, curCol + 1});
                changed = true;
                tomatoes--;
            }
            if (curCol - 1 >= 0 && matrix[curRow][curCol - 1] == 0) {
                matrix[curRow][curCol - 1] = 1;
                candidates.push(new int[2] {curRow, curCol - 1});
                changed = true;
                tomatoes--;
            }

            boolM[curRow][curCol] = true;
        }

        if (queNum == 0 && changed){
            changed = false;
            days++;
            queNum = (int)candidates.size();
        } else if (queNum == 0 && !changed) {
            break;
        }
    } 

    if (tomatoes == 0)
        cout << days;
    else
        cout << -1;
}