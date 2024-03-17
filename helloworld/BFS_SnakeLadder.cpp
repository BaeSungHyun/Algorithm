#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int x, y;

    int cell[101];
    bool visited[101];

    for (int i = 0; i < 101; i++) {
        cell[i] = i;
        visited[i] = false;
    }
    
    for (int i = 0; i < N + M; i++) {
        cin >> x >> y;
        cell[x] = y;
    }

    queue<pair<int, int>> q;
    q.push({cell[1], 0});
    visited[1] = true;

    int min {100};
    
    while (!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();

        int i;

        for (i = 1; i <= 6 && temp.first + i < 100; i++) {
            if (visited[cell[temp.first + i]] == false) {
                visited[cell[temp.first + i]] = true;
                q.push({cell[temp.first + i], temp.second + 1});
            }
        }
        if (i == 7) i = 6;

        if (temp.first + i == 100 && min > temp.second) {
            min = ++temp.second;
        }
        
    }

    cout << min;
} 