#include <iostream>
#include <chrono>

using namespace std;

int main() {
    auto start = std::chrono::high_resolution_clock::now();

    const int norm = 1000;

    short arr[norm][norm];
    for (int i = 0; i < norm; i++) {
        for (int j = 0; j < norm; j++) {
            arr[i][j] = 1;    
        } 
    }
    for (int i = 0; i < norm; i++) {
        for (int j = 0; j < norm; j++) {
            arr[i][j] = 1;    
        } 
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;


    start = std::chrono::high_resolution_clock::now();

    int** matrix = new int*[norm];
    for (int i = 0; i < norm; i++) {
        matrix[i] = new int[norm];
        for (int j = 0; j < norm; j++) {
            matrix[i][j] = 1;
        }
    }
    for (int i = 0; i < norm; i++) {
        for (int j = 0; j < norm; j++) {
            matrix[i][j] = 1;    
        } 
        // delete[] matrix[i];
    }
    // delete[] matrix;


    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
}