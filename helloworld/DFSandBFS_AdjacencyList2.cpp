#include <iostream>
#include <list>
#include <iterator>

using namespace std;

list<int>* edges;
bool* dfsBool;

void DFS(int vertex) {
    cout << vertex << " ";
    dfsBool[vertex] = true;

    for (int next : edges[vertex]) {
        if (!dfsBool[next]) {
            dfsBool[next] = true;
            DFS(next);
        }
    }
}

void reset(const int vertexNum) {
    for (int i = 1; i <= vertexNum; i++) {
        dfsBool[i] = false;
    }
}

void BFS(int vertex) {
    cout << vertex << " ";
    dfsBool[vertex] = true;

    list<int> vertexes;
    vertexes.push_back(vertex);

    while (!vertexes.empty()) {
        int v = vertexes.front();
        vertexes.pop_front();

        for (int next : edges[v]) {
            if (!dfsBool[next]){
                dfsBool[next] = true;
                vertexes.push_back(next);
                cout << next << " ";
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

    edges = new list<int> [vertexNum + 1];

    dfsBool = new bool[vertexNum + 1];

    int tempX, tempY;

    // INITIALIZE
    for (int i = 1; i <= edgeNum; i++) {
        cin >> tempX >> tempY;
        edges[tempX].push_back(tempY);
        edges[tempY].push_back(tempX);
    }

    for (int i = 1; i <= vertexNum; i++) {
        edges[i].sort();
        dfsBool[i] = false;
    }

    // TRAVERSE
    DFS(startingVertex);
    reset(vertexNum);
    cout << "\n";
    BFS(startingVertex);
} 