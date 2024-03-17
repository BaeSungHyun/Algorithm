#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct coordinates {
    int row; 
    int col;

    coordinates(int _row, int _col) {
        row = _row;
        col = _col;
    }
}; 

void traverse(char input[25][26], int N, bool visited[25][25], int count[25], int &index) {
    queue<coordinates*> q;
    index = -1;
    int i = 0;


    do {
        for (; i < N * N; i++) {
            if (input[i / N][i % N] == '1' && visited[i / N][i % N] == false) {
                index++;
                count[index]++;
                break;
            }
        }

        q.push(new coordinates(i / N, i % N));

        while (!q.empty()) {
            coordinates* temp = q.front();
            q.pop();
            visited[temp->row][temp->col] = true;

            if (temp->row + 1 < N && input[temp->row + 1][temp->col] == '1' && visited[temp->row + 1][temp->col] == false) {
                count[index]++;
                q.push(new coordinates(temp->row + 1, temp->col));
                visited[temp->row + 1][temp->col] = true;
            } 
            if (temp->col + 1 < N && input[temp->row][temp->col + 1] == '1' && visited[temp->row][temp->col + 1] == false) {
                count[index]++;
                q.push(new coordinates(temp->row, temp->col + 1));
                visited[temp->row][temp->col + 1] = true;
            }
            if (temp->row - 1 >= 0 && input[temp->row - 1][temp->col] == '1' && visited[temp->row - 1][temp->col] == false) {
                count[index]++;
                q.push(new coordinates(temp->row - 1, temp->col));
                visited[temp->row - 1][temp->col] = true;
            }
            if (temp->col - 1 >= 0 && input[temp->row][temp->col - 1] == '1' && visited[temp->row][temp->col - 1] == false) {
                count[index]++;
                q.push(new coordinates(temp->row, temp->col - 1));
                visited[temp->row][temp->col - 1] = true;
            }

            delete temp;
        }
    } while (i < N * N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    char input[25][26]; // zero-indexing
    int count[625];

    bool visited[25][25];

    for (int i = 0; i < N; i++) {
        cin >> input[i];
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
            count[i * N + j] = 0;
        }
    }

    int index;
    traverse(input, N, visited, count, index);

    sort(count, count + index + 1);

    cout << index + 1 << "\n";
    for (int k = 0; k <= index; k++) {
        cout << count[k] << "\n";
    }
    // while (count[k] != 0) 
    //     cout << count[k++] << "\n";
}