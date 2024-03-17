#include <iostream>
#include <list>

using namespace std;

void DFS(list<int>* edges, bool* visited, int start, int& answer) {
    visited[start] = true;

    for (auto i = edges[start].begin(); i != edges[start].end(); i++) {
        if (visited[*i] == false) {
            visited[*i] = true;
            DFS(edges, visited, *i, answer);
            answer++;
        }
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numVer, numEdg;

    cin >> numVer;
    cin >> numEdg;

    list<int> computers[numVer + 1]; // 1-indexing
    
    for (int i = 0; i < numEdg; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        computers[temp1].push_back(temp2);
        computers[temp2].push_back(temp1);
    }
    int answer = 0;
    bool visited[numVer + 1];
    for (int i = 0; i < numVer + 1; i++) {
        visited[i] = false;
    }

    DFS(computers, visited, 1, answer);

    cout << answer;
}