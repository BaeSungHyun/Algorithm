// Union / Find
#include <iostream>
#include <chrono>

using namespace std;

short findFunc(short *arr, short i) {
    if (arr[i] < 0) return i; // itself is root
    else {
        return arr[i] = findFunc(arr, arr[i]);
    }
}

void unionFunc(short *arr, short i, short j) {
    short root1 = findFunc(arr, i);
    short root2 = findFunc(arr, j);

    if (root1 != root2)
        arr[root1] = root2;

    // if (root1 != root2) {
    //     if (arr[root1] <= arr[root2]) { // root1 bigger
    //         arr[root2] = root1;
    //         arr[root1]--;
    //     } else if (arr[root2] < arr[root1]) {// root2 bigger
    //         arr[root1] = root2;
    //         arr[root2]--;
    //     }
    // }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int numVertex, numEdge;
    cin >> numVertex >> numEdge;
    
    auto start = std::chrono::high_resolution_clock::now();

    // initialize array to -1 indicating 'root'
    short arr [1000 + 1]; // 1-indexing
    for (int i = 1; i <= 1000; i++) {
        arr[i] = -1;
    }

    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate duration
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;


    for (int i = 0; i < numEdge; i++) {
        short temp1, temp2;
        cin >> temp1 >> temp2;

        unionFunc(arr, temp1, temp2);
    }

    int sum {0};
    for (int i = 1; i <= numVertex; i++) {
        if (arr[i] < 0) {
            sum++;
        }
    }
    cout << sum;
} 