#include <iostream>
#include <queue>

using namespace std;

void DFS(bool** matrix, bool* dfsBool, int vertex, const int& vertexNum) {
    cout << vertex << " ";
    dfsBool[vertex] = true;
    
    for (int i = 1; i <= vertexNum; i++) {
        if (!dfsBool[i] && matrix[vertex][i]) {
            dfsBool[i] = true;
            DFS(matrix, dfsBool, i, vertexNum);
        }
    }
}

void BFS(bool** matrix, bool* bfsBool, int vertex, const int vertexNum) {
    cout << vertex << " ";
    bfsBool[vertex] = true;

    queue<int> vertexes;
    vertexes.push(vertex);

    while (!vertexes.empty()) {
        int v = vertexes.front();
        vertexes.pop();

        for (int i = 1; i <= vertexNum; i++) {
            if (!bfsBool[i] && matrix[v][i]) {
                vertexes.push(i);
                bfsBool[i] = true;
                cout << i << " ";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertexNum, edgeNum, startingVertex;

    cin >> vertexNum >> edgeNum >> startingVertex;

    bool** matrix = new bool*[vertexNum + 1]; // 1-indexing
    bool* dfsBool = new bool[vertexNum + 1]; // 1-indexing
    bool* bfsBool = new bool[vertexNum + 1]; // 1-indexing
    

    // INITIALIZE
    for (int i = 1; i <= vertexNum; i++) {
        matrix[i] = new bool[vertexNum + 1]; // 1-indexing
        dfsBool[i] = false;
        bfsBool[i] = false;
        for (int j = 1; j <= vertexNum; j++) 
            matrix[i][j] = false;
    }

    int tempX, tempY;
    for (int i = 0; i < edgeNum; i++) {
        cin >> tempX >> tempY;
        matrix[tempX][tempY] = true;
        matrix[tempY][tempX] = true;
    }


    // TRAVERSE
    DFS(matrix, dfsBool, startingVertex, vertexNum);
    cout << "\n";
    BFS(matrix, bfsBool, startingVertex, vertexNum);
}