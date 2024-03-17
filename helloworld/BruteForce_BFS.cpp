#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct coordi {
    int x;
    int y;
    int xBefore;
    int yBefore;
    int count;
    int sum;

    coordi(int _x, int _y, int _bx, int _by, int _s, int _c) {
        x = _x;
        y = _y;
        xBefore = _bx;
        yBefore = _by;
        sum = _s;
        count = _c;
    }
};

// +1, 0 - 총 4가지 가능 -> 이 4가지 경우를 어떻게 효율적으로 가능? 4^4 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int matrix[500][500];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    queue<coordi> q;

    int max {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            q.push(coordi(i, j, 0, 0, matrix[i][j], 0));

            int unique[4];
            int uniqueIndex{0};
            
            if (i - 1 >= 0) {
                unique[uniqueIndex++] = matrix[i - 1][j];
            } 
            if (i + 1 < N) {
                unique[uniqueIndex++] = matrix[i + 1][j];
            }
            if (j - 1 >= 0) {
                unique[uniqueIndex++] = matrix[i][j - 1];
            }
            if (j + 1 < M) {
                unique[uniqueIndex++] = matrix[i][j + 1];
            }

            if (uniqueIndex >= 2) {
                sort(unique, unique + uniqueIndex, greater<int>());
                if (max < matrix[i][j] + unique[0] + unique[1] + unique[2])
                    max = matrix[i][j] + unique[0] + unique[1] + unique[2];
            }
            

            while (!q.empty()) {
                coordi temp = q.front();
                q.pop();

                if (temp.count == 3) {
                    if (max < temp.sum) {
                        max = temp.sum;
                    }
                    continue;
                } 

                if (temp.x + 1 < N && temp.xBefore != -1) {
                    coordi cur(temp.x + 1, temp.y, 1, 0, temp.sum + matrix[temp.x + 1][temp.y], temp.count + 1);
                    q.push(cur);
                }
                if (temp.x - 1 >= 0 && temp.xBefore != 1) {
                    coordi cur(temp.x - 1, temp.y, -1, 0, temp.sum + matrix[temp.x - 1][temp.y], temp.count + 1);
                    q.push(cur);
                }
                if (temp.y + 1 < M && temp.yBefore != -1) {
                    coordi cur(temp.x, temp.y + 1, 0, 1, temp.sum + matrix[temp.x][temp.y + 1], temp.count + 1);
                    q.push(cur);
                } 
                if (temp.y - 1 >= 0 && temp.yBefore != 1) {
                    coordi cur(temp.x, temp.y - 1, 0, -1, temp.sum + matrix[temp.x][temp.y - 1], temp.count + 1);
                    q.push(cur);
                }
            }
        }
    }

    cout << max;
}