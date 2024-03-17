#include <iostream>
#include <queue>

using namespace std;

struct coordi {
    int x;
    int y;
    coordi(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

int normalTraverse(char mat[100][100], bool b[100][100], int n, queue<coordi>& q) {
    coordi current = q.front();
    q.pop();
    char target = mat[current.x][current.y];
    b[current.x][current.y] = true;

    int count{1};

    queue<coordi> tempQ;
    tempQ.push(coordi(current.x, current.y));
    
    while (!q.empty()) {

        while (!q.empty() && b[q.front().x][q.front().y] != false) {
            q.pop();
        }

        if (tempQ.empty() && !q.empty()) {
            current = q.front();
            tempQ.push(coordi(current.x, current.y));
            q.pop();
            b[current.x][current.y] = true;
            count++;
        }

        while (!tempQ.empty()) {
            coordi temp = tempQ.front();
            tempQ.pop();

            // no queue push below. All candidates are pushed during input
            if (temp.x + 1 < n && mat[temp.x + 1][temp.y] == target && b[temp.x + 1][temp.y] == false) {
                b[temp.x + 1][temp.y] = true;
                tempQ.push(coordi(temp.x + 1, temp.y));
            }
            if (temp.y + 1 < n && mat[temp.x][temp.y + 1] == target && b[temp.x][temp.y + 1] == false) {
                b[temp.x][temp.y + 1] = true;
                tempQ.push(coordi(temp.x, temp.y + 1));
            }
            if (temp.x -1 >= 0 && mat[temp.x - 1][temp.y] == target && b[temp.x - 1][temp.y] == false) {
                b[temp.x - 1][temp.y] = true;
                tempQ.push(coordi(temp.x - 1, temp.y));
            }
            if (temp.y - 1 >= 0 && mat[temp.x][temp.y - 1] == target && b[temp.x][temp.y - 1] == false) {
                b[temp.x][temp.y - 1] = true;
                tempQ.push(coordi(temp.x, temp.y - 1));
            }
        }    
    }

    return count;
}

int blindTraverse(char mat[100][100], bool b[100][100], int n, queue<coordi>& q) {
    coordi current = q.front();
    q.pop();
    char target = mat[current.x][current.y];

    char target1;
    switch (target) {
        case 'R': {
            target1 = 'G';
            break;
        }
        case 'G': {
            target1 = 'R';
            break;
        } 
        case 'B': {
            target1 = 'B';
            break;
        }
    }

    b[current.x][current.y] = true;

    int count{1};

    queue<coordi> tempQ;
    tempQ.push(coordi(current.x, current.y));
    
    while (!q.empty()) {

        while (!q.empty() && b[q.front().x][q.front().y] != false) {
            q.pop();
        }

        if (tempQ.empty() && !q.empty()) {
            current = q.front();
            tempQ.push(coordi(current.x, current.y));
            q.pop();
            b[current.x][current.y] = true;
            count++;
        }

        while (!tempQ.empty()) {
            coordi temp = tempQ.front();
            tempQ.pop();

            // no queue push below. All candidates are pushed during input
            if (temp.x + 1 < n && (mat[temp.x + 1][temp.y] == target || mat[temp.x + 1][temp.y] == target1) && b[temp.x + 1][temp.y] == false) {
                b[temp.x + 1][temp.y] = true;
                tempQ.push(coordi(temp.x + 1, temp.y));
            }
            if (temp.y + 1 < n && (mat[temp.x][temp.y + 1] == target || mat[temp.x][temp.y + 1] == target1) && b[temp.x][temp.y + 1] == false) {
                b[temp.x][temp.y + 1] = true;
                tempQ.push(coordi(temp.x, temp.y + 1));
            }
            if (temp.x -1 >= 0 && (mat[temp.x - 1][temp.y] == target || mat[temp.x - 1][temp.y] == target1) && b[temp.x - 1][temp.y] == false) {
                b[temp.x - 1][temp.y] = true;
                tempQ.push(coordi(temp.x - 1, temp.y));
            }
            if (temp.y - 1 >= 0 && (mat[temp.x][temp.y - 1] == target || mat[temp.x][temp.y - 1] == target1) && b[temp.x][temp.y - 1] == false) {
                b[temp.x][temp.y - 1] = true;
                tempQ.push(coordi(temp.x, temp.y - 1));
            }
        }    
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    char matrix[100][100];

    bool normalB [100][100];
    bool blindB [100][100];

    queue<coordi> rQ;
    queue<coordi> gQ;
    queue<coordi> bQ;
    queue<coordi> rgQ;
    queue<coordi> bbQ;

    for (int i = 0; i < N; i++) {
        cin >> matrix[i];
        for (int j = 0; j < N; j++) {
            normalB[i][j] = false;
            blindB[i][j] = false;

            switch (matrix[i][j]) {
                case 'R': {
                    rQ.push(coordi(i, j));
                    rgQ.push(coordi(i, j));
                    break;
                }
                case 'G': {
                    gQ.push(coordi(i, j));
                    rgQ.push(coordi(i, j));
                    break;
                }
                case 'B': {
                    bQ.push(coordi(i, j));
                    bbQ.push(coordi(i, j));
                    break;
                }
            }
        }
    }

    int x = rQ.empty() ? 0 : normalTraverse(matrix, normalB, N, rQ);
    int y = gQ.empty() ? 0 : normalTraverse(matrix, normalB, N, gQ);
    int z = bQ.empty() ? 0 : normalTraverse(matrix, normalB, N, bQ);

    cout << x + y + z << " ";

    x = rgQ.empty() ? 0 : blindTraverse(matrix, blindB, N, rgQ);
    y = bbQ.empty() ? 0 : blindTraverse(matrix, blindB, N, bbQ);

    cout << x + y;
}