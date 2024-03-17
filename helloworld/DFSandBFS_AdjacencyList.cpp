#include <iostream>
#include <list>
#include <iterator>

using namespace std;

list<int>* edges;
list<int>::iterator* iterators;
bool* dfsBool;

void DFS(int vertex) {
    cout << vertex << " ";
    dfsBool[vertex] = true;

    while (iterators[vertex] != edges[vertex].end()) {
        if (!dfsBool[*(iterators[vertex])]) {
            dfsBool[*(iterators[vertex])] = true;
            DFS(*(iterators[vertex]));
        }
        iterators[vertex]++;
    }
}

void reset(const int vertexNum) {
    for (int i = 1; i <= vertexNum; i++) {
        iterators[i] = edges[i].begin();
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

        while (iterators[v] != edges[v].end()) {
            if (!dfsBool[*(iterators[v])]) {
                vertexes.push_back(*(iterators[v]));
                dfsBool[*(iterators[v])] = true;
                cout << *(iterators[v]) << " ";
            }
            iterators[v]++;
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
    iterators = new list<int>::iterator [vertexNum + 1];

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
        iterators[i] = edges[i].begin();
    }

    // TRAVERSE
    DFS(startingVertex);
    reset(vertexNum);
    cout << "\n";
    BFS(startingVertex);
} 